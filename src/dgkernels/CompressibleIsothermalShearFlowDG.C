/* -------------------------------------------------------------------------------
    slug - a finite element solver for simulation of lubrication films
    Copyright (C) 2015 Adam Lange

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
  ----------------------------------------------------------------------------- */

#include "CompressibleIsothermalShearFlowDG.h"

template<>
InputParameters validParams<CompressibleIsothermalShearFlowDG>()
{
  InputParameters params = validParams<DGKernel>();
  params.addParam<Real>("alpha",0.0,"Upwinding factor: 0 (central) -> 1 (full upwind)");
  params.addRequiredCoupledVar("h","film thickness");
  params.addRequiredParam<RealVectorValue>("vel_surface","sliding velocity");
  return params;
}

CompressibleIsothermalShearFlowDG::CompressibleIsothermalShearFlowDG(const InputParameters &parameters) :
    DGKernel(parameters),
    _alpha(getParam<Real>("alpha")),
    _mu(getMaterialPropertyByName<Real>("mu")),
    _h(coupledValue("h")),
    _v(getParam<Real>("vel_surface"))
{
}

Real
CompressibleIsothermalShearFlowDG::computeQpResidual(Moose::DGResidualType type)
{
  Real r;

  if (_v*_normals[_qp]>=0)
  {
    r = _test[_i][_qp]*6.0*_mu[_qp]*_h[_qp]*_u[_qp]*_v*_normals[_qp];
  }
  else
  {
    r = _test[_i][_qp]*6.0*_mu[_qp]*_h[_qp]*_u_neighbor[_qp]*_v*_normals[_qp];
  }

  switch (type)
  {
  case Moose::Element:
    r = r;
    break;

  case Moose::Neighbor:
    r = -r;
    break;
  }

  return r;
}

Real
CompressibleIsothermalShearFlowDG::computeQpJacobian(Moose::DGJacobianType type)
{
  Real r=0;
  switch (type)
  {
  case Moose::ElementElement:
    if (_v*_normals[_qp]>=0)
    {
      r = _test[_i][_qp]*6.0*_mu[_qp]*_h[_qp]*_phi[_j][_qp]*_v*_normals[_qp];
    }
    else 
    {
      r = 0;
    }
    break;

  case Moose::ElementNeighbor:
    if (_v*_normals[_qp]>=0)
    {
      r = 0;
    }
    else
    {
      r = _test[_i][_qp]*6.0*_mu[_qp]*_h[_qp]*_phi_neighbor[_j][_qp]*_v*_normals[_qp];
    }
    break;

  case Moose::NeighborElement:
    if (_v*_normals[_qp]>=0)
    {
      r = -_test[_i][_qp]*6.0*_mu[_qp]*_h[_qp]*_phi[_j][_qp]*_v*_normals[_qp];
    }
    else
    {
      r = 0;
    }
    break;

  case Moose::NeighborNeighbor:
    if (_v*_normals[_qp]>=0)
    {
      r = 0;
    }
    else
    {
      r = -_test[_i][_qp]*6.0*_mu[_qp]*_h[_qp]*_phi_neighbor[_j][_qp]*_v*_normals[_qp];
    }
    break;
  }

  return r;
}
