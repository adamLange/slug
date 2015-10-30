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

#include "CompressibleIsothermalPressureFlowDG.h"

template<>
InputParameters validParams<CompressibleIsothermalPressureFlowDG>()
{
  InputParameters params = validParams<DGKernel>();
  params.addRequiredParam<Real>("tau","interior penalty coefficient");
  params.addRequiredCoupledVar("h","film thickness coupled var");
  return params;
}

CompressibleIsothermalPressureFlowDG::CompressibleIsothermalPressureFlowDG(const InputParameters &parameters) :
  DGKernel(parameters),
  _tau(getParam<Real>("tau")),
  _mu(getMaterialPropertyByName<Real>("mu")),
  _h(coupledValue("h"))
{

}

Real
CompressibleIsothermalPressureFlowDG::computeQpResidual(Moose::DGResidualType type)
{
  Real r = 0;

  switch (type)
  {
  case Moose::Element:
    r = _test[_i][_qp]*(0.5*pow(_h[_qp],3)*(_u[_qp]*_grad_u[_qp]+_u_neighbor[_qp]*_grad_u_neighbor[_qp])*_normals[_qp]-_tau*(_u[_qp]-_u_neighbor[_qp]));
    break;

  case Moose::Neighbor:
    r = -_test_neighbor[_i][_qp]*(0.5*pow(_h[_qp],3)*(_u[_qp]*_grad_u[_qp]+_u_neighbor[_qp]*_grad_u_neighbor[_qp])*_normals[_qp]-_tau*(_u_neighbor[_qp]-_u[_qp]));
    break;
  }

  return r;
}

Real
CompressibleIsothermalPressureFlowDG::computeQpJacobian(Moose::DGJacobianType type)
{
  Real r = 0;

  switch (type)
  {
  case Moose::ElementElement:
    r = _test[_i][_qp]*(0.5*pow(_h[_qp],3)*(_phi[_j][_qp]*_grad_u[_qp]+_u[_qp]*_grad_phi[_j][_qp])*_normals[_qp]-_tau*_phi[_j][_qp]);
    break;

  case Moose::ElementNeighbor:
    r = _test[_i][_qp]*(0.5*pow(_h[_qp],3)*(_phi_neighbor[_j][_qp]*_grad_u_neighbor[_qp]+_u_neighbor[_qp]*_grad_phi_neighbor[_j][_qp])*_normals[_qp]+_tau*_phi_neighbor[_j][_qp]);
    break;

  case Moose::NeighborElement:
    r = _test_neighbor[_i][_qp]*(-0.5*pow(_h[_qp],3)*(_phi[_j][_qp]*_grad_u[_qp]+_u[_qp]*_grad_phi[_j][_qp])*_normals[_qp]+_tau*_phi[_j][_qp]);
    break;

  case Moose::NeighborNeighbor:
    r = _test_neighbor[_i][_qp]*(-0.5*pow(_h[_qp],3)*(_phi_neighbor[_j][_qp]*_grad_u_neighbor[_qp]+_u_neighbor[_qp]*_grad_phi_neighbor[_j][_qp])*_normals[_qp]-_tau*_phi_neighbor[_j][_qp]);
    break;
  }

  return r;
}
