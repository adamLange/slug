[GlobalParams]
  vel_surface = '40 0 0'
[]

[Mesh]
  type = FileMesh
  file = simpleAirBearingMesh.unv
  uniform_refine = 4
[]

[Variables]
  [./p]
    order = FIRST
    family = MONOMIAL
    [./InitialCondition]
      type = ConstantIC
      value = 100e3
    [../]
  [../]
[]

[AuxVariables]
  [./h]
    order = FIRST
    family = LAGRANGE
  [../]
  [./m_dot_x]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./m_dot_y]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./sigma_zx]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./sigma_zy]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Kernels]
  active = 'TimeDerivative ShearFlow'
  [./TimeDerivative]
    type = CompressibleIsothermalPTimeDerivative
    variable = p
    h = h
  [../]
  [./ShearFlow]
    type = CompressibleIsothermalShearFlow
    variable = p
    h = h
  [../]
  [./PressureFlow]
    type = CompressibleIsothermalPressureFlow
    variable = p
    h = h
  [../]
[]

[DGKernels]
  active = 'ShearFlowDG'
  [./ShearFlowDG]
    type = CompressibleIsothermalShearFlowDG
    variable = p
    h = h
  [../]
  [./PressureFlowDG]
    type = CompressibleIsothermalPressureFlowDG
    variable = p
    tau = 1.0
    h = h
  [../]
[]

[AuxKernels]
  [./h]
    type = AlphaBetaH
    variable = h
    alpha = 0
    beta = 0
    h = 1e-3
    execute_on = initial
  [../]
  [./m_dot_x]
    type = ReynoldsMassFlow
    variable = m_dot_x
    component = 0
    p = p
    h = h
  [../]
  [./m_dot_y]
    type = ReynoldsMassFlow
    variable = m_dot_y
    component = 1
    p = p
    h = h
  [../]
  [./sigma_zx]
    type = ReynoldsShearStress
    variable = sigma_zx
    component = 0
    p = p
    h = h
  [../]
  [./sigma_zy]
    type = ReynoldsShearStress
    variable = sigma_zy
    component = 1
    p = p
    h = h
  [../]
[]

[Postprocessors]
  [./F_z_p]
    type = ElementIntegralVariablePostprocessor
    variable = p
  [../]
  [./massFlow]
    type = ReynoldsMassFlowIntegral
    cross_film_m_dot_x = m_dot_x
    cross_film_m_dot_y = m_dot_y
    boundary = outer
  [../]
  [./Mx_p]
    type = PressureMomentPointDirection
    pressure = p
    normal = '0 0 1'
    axis = '1 0 0'
    point = '0 0 0'
  [../]
  [./My_p]
    type = PressureMomentPointDirection
    pressure = p
    normal = '0 0 1'
    axis = '0 1 0'
    point = '0 0 0'
  [../]
  [./Mx_shear]
    type = ReynoldsShearMoment
    sigma_zx = sigma_zx
    sigma_zy = sigma_zy
    point = '0 0 0'
    axis = '1 0 0'
  [../]
  [./My_shear]
    type = ReynoldsShearMoment
    sigma_zx = sigma_zx
    sigma_zy = sigma_zy
    point = '0 0 0'
    axis = '0 1 0'
  [../]
  [./Mz_shear]
    type = ReynoldsShearMoment
    sigma_zx = sigma_zx
    sigma_zy = sigma_zy
    point = '0 0 0'
    axis = '0 0 1'
  [../]
  [./F_x_s]
    type = ElementIntegralVariablePostprocessor
    variable = sigma_zx
  [../]
  [./F_y_s]
    type = ElementIntegralVariablePostprocessor
    variable = sigma_zy
  [../]
[]

[BCs]
  active = 'outsideInOut innerInOut'
  [./outsideDirichlet]
    type = DirichletBC
    variable = p
    boundary = outer
    value = 100e3
    h = h
  [../]
  [./inletDirichlet]
    type = DirichletBC
    variable = p
    boundary = inner
    h = h
    value = 450e3
  [../]
  [./outsideInOut]
    type = CompressibleIsothermalShearInflowOutflowBC
    variable = p
    boundary = outer
    h = h
    p_bc = 100e3
  [../]
  [./innerInOut]
    type = CompressibleIsothermalShearInflowOutflowBC
    variable = p
    boundary = outer
    h = h
    p_bc = 120e3
  [../]
[]

[Materials]
  [./air]
    type = ReynoldsIdealGas
    block = 0
    temp = 300 # K
    p = p
  [../]
[]

[Executioner]
  # Preconditioned JFNK (default)
  # nl_rel_tol = 1e-12
  type = Transient
  dt = 0.00001
  l_max_its = 25
  nl_max_its = 200
  nl_rel_step_tol = 1e-4
  l_tol = 1e-15
  end_time = 0.005
[]

[Outputs]
  [./console]
    type = Console
    perf_log = true
    perf_header = true
  [../]
  [./exodus]
    type = Exodus
    execute_on = 'initial timestep_end'
    elemental_as_nodal = true
  [../]
  [./csv]
    type = CSV
    execute_postprocessors_on = timestep_end
  [../]
[]

