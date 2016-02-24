/* -------------------------------------------------------------------------------
    slug - a finite element solver for lubrication films
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
#ifndef REYNOLDSMEANVELOCITY_H
#define REYNOLDSMEANVELOCITY_H

#include "AuxKernel.h"

class ReynoldsMeanVelocity;

template<>
InputParameters validParams<ReynoldsMeanVelocity>();

class ReynoldsMeanVelocity : public AuxKernel
{
public:

  ReynoldsMeanVelocity(const InputParameters & parameters);

protected:
  virtual Real computeValue();

  unsigned _component;
  RealVectorValue _vel_surface;
  const MaterialProperty<Real> & _mu;
  const VariableGradient & _grad_p;
  const VariableValue & _h;

};

#endif //REYNOLDSMEANVELOCITY_H
