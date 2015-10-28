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

#include "CompressibleIsothermalPTimeDerivative.h"

template<>
InputParameters validParams<CompressibleIsothermalPTimeDerivative>()
{
  InputParameters params = validParams<TimeKernel>();
  params.addRequiredCoupledVar("h","Film thickness");
  return params;
}

CompressibleIsothermalPTimeDerivative::CompressibleIsothermalPTimeDerivative(const InputParameters & parameters) :
  TimeKernel(parameters),
  _h(coupledValue("h")),
  _mu(getMaterialPropertyByName<Real>("mu"))
{
}

Real
CompressibleIsothermalPTimeDerivative::computeQpResidual()
{
  return _test[_i][_qp]*12*_mu[_qp]*_h[_qp]*_u_dot[_qp];
}

Real
CompressibleIsothermalPTimeDerivative::computeQpJacobian()
{
  return _test[_i][_qp]*12*_mu[_qp]*_h[_qp]*_phi[_j][_qp]*_du_dot_du[_qp];
}
