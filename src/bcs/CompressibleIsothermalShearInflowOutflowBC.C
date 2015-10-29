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

#include "CompressibleIsothermalShearInflowOutflowBC.h"

template<>
InputParameters validParams<CompressibleIsothermalShearInflowOutflowBC>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("h","film thickness");
  params.addRequiredParam<FunctionName>("p_bc","pressure boundary condition function name");
  params.addRequiredParam<RealVectorValue>("vel_surface","surface velocity");
  return params;
}

CompressibleIsothermalShearInflowOutflowBC::CompressibleIsothermalShearInflowOutflowBC(const InputParameters & parameters) :
  IntegratedBC(parameters),
  _h(coupledValue("h")),
  _mu(getMaterialPropertyByName<Real>("mu")),
  _p_bc(getFunction("p_bc")),
  _v(getParam<RealVectorValue>("vel_surface"))
{
}

Real
CompressibleIsothermalShearInflowOutflowBC::computeQpResidual()
{
  Real r;
  if (_v*_normals[_qp]>0)
  {
    r = _test[_i][_qp]*6*_mu[_qp]*_h[_qp]*_u[_qp]*_v*_normals[_qp];
  }
  else
  {
    r = _test[_i][_qp]*6*_mu[_qp]*_h[_qp]*_p_bc.value(_t,_q_point[_qp])*_v*_normals[_qp];
  }
  return r;
}

Real
CompressibleIsothermalShearInflowOutflowBC::computeQpJacobian()
{
  Real r;
  if (_v*_normals[_qp]>0)
  {
    r = _test[_i][_qp]*6*_mu[_qp]*_h[_qp]*_phi[_j][_qp]*_v*_normals[_qp];
  }
  else
  {
    r = 0;
  }
  return r;
}
