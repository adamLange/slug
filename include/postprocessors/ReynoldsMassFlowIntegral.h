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

#ifndef REYNOLDSMASSFLOWINTEGRAL_H
#define REYNOLDSMASSFLOWINTEGRAL_H

#include "SideIntegralPostprocessor.h"

class ReynoldsMassFlowIntegral;

template<>
InputParameters validParams<ReynoldsMassFlowIntegral>();

class ReynoldsMassFlowIntegral : public SideIntegralPostprocessor
{
public:
  ReynoldsMassFlowIntegral(const InputParameters & parameters);

protected:
  virtual Real computeQpIntegral();

  const VariableValue & _m_dot_x;
  const VariableValue & _m_dot_y;
};

#endif // REYNOLDSMASSFLOWINTEGRAL_H
