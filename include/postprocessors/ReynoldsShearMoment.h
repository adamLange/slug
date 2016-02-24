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

#ifndef REYNOLDSSHEARMOMENT_H
#define REYNOLDSSHEARMOMENT_H

#include "ElementIntegralPostprocessor.h"

class ReynoldsShearMoment;

template<>
InputParameters validParams<ReynoldsShearMoment>();

class ReynoldsShearMoment : public ElementIntegralPostprocessor
{
public:

  ReynoldsShearMoment(const InputParameters & parameters);

protected:

  virtual Real computeQpIntegral();
  const VariableValue & _sigma_zx;
  const VariableValue & _sigma_zy;
  const RealVectorValue & _point;
  const RealVectorValue & _axisIn;
  const RealVectorValue _axis;

};

#endif // REYNOLDSSHEARMOMENT_H
