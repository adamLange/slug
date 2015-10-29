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
#include "SlugApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

#include "CompressibleReynoldsPressure.h"
#include "ReynoldsIdealGas.h"
#include "ReynoldsMeanVelocity.h"
#include "ReynoldsMassFlow.h"
#include "RadialBearingH.h"
#include "AlphaBetaH.h"
#include "ReynoldsMassFlowIntegral.h"
#include "PressureMomentPointDirection.h"
#include "ReynoldsShearStress.h"
#include "ReynoldsShearMoment.h"
#include "CompressibleIsothermalShearFlow.h"
#include "CompressibleIsothermalPressureFlow.h"
#include "CompressibleIsothermalShearFlowDG.h"
#include "CompressibleIsothermalPressureFlowDG.h"
#include "CompressibleIsothermalPTimeDerivative.h"
#include "CompressibleIsothermalShearInflowOutflowBC.h"

template<>
InputParameters validParams<SlugApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

SlugApp::SlugApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  SlugApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  SlugApp::associateSyntax(_syntax, _action_factory);
}

SlugApp::~SlugApp()
{
}

// External entry point for dynamic application loading
extern "C" void SlugApp__registerApps() { SlugApp::registerApps(); }
void
SlugApp::registerApps()
{
  registerApp(SlugApp);
}

// External entry point for dynamic object registration
extern "C" void SlugApp__registerObjects(Factory & factory) { SlugApp::registerObjects(factory); }
void
SlugApp::registerObjects(Factory & factory)
{
  registerKernel(CompressibleReynoldsPressure);
  registerKernel(CompressibleIsothermalShearFlow);
  registerKernel(CompressibleIsothermalPressureFlow);
  registerAux(ReynoldsMeanVelocity);
  registerAux(ReynoldsMassFlow);
  registerAux(AlphaBetaH);
  registerMaterial(ReynoldsIdealGas);
  registerAux(RadialBearingH);
  registerPostprocessor(ReynoldsMassFlowIntegral);
  registerPostprocessor(PressureMomentPointDirection);
  registerAux(ReynoldsShearStress);
  registerPostprocessor(ReynoldsShearMoment);
  registerDGKernel(CompressibleIsothermalShearFlowDG);
  registerDGKernel(CompressibleIsothermalPressureFlowDG);
  registerKernel(CompressibleIsothermalPTimeDerivative);
  registerBoundaryCondition(CompressibleIsothermalShearInflowOutflowBC);
}

// External entry point for dynamic syntax association
extern "C" void SlugApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { SlugApp::associateSyntax(syntax, action_factory); }
void
SlugApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
