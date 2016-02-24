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

#ifndef REYNOLDSSHEARSTRESS_H
#define REYNOLDSSHEARSTRESS_H

#include "AuxKernel.h"

class ReynoldsShearStress;

template<>
InputParameters validParams<ReynoldsShearStress>();

class ReynoldsShearStress: public AuxKernel
{
public:

  ReynoldsShearStress(const InputParameters & parameters);

protected:

  virtual Real computeValue();

  unsigned _component;
  const VariableGradient & _grad_p;
  const VariableValue & _h;
  const MaterialProperty<Real> & _mu;
  const RealVectorValue & _vel_surface;

};
#endif // REYNOLDSSHEARSTRESS_H
