CDF      
      
len_string     !   len_line   Q   four      	time_step          len_name   !   num_dim       	num_nodes         num_elem   
   
num_el_blk        num_node_sets         num_side_sets         num_el_in_blk1     
   num_nod_per_el1       num_side_ss1      num_side_ss2      num_nod_ns1       num_nod_ns2       num_nod_var       num_elem_var      num_info  �         api_version       @�
=   version       @�
=   floating_point_word_size            	file_size               int64_status             title         shearStress_out.e      maximum_name_length                    
time_whole                            �   	eb_status                             �   eb_prop1               name      ID              �   	ns_status         	                    �   ns_prop1      	         name      ID              �   	ss_status         
                    �   ss_prop1      
         name      ID              �   coordx                      X      �   coordy                      X      	   coordz                      X      	\   eb_names                       $      	�   ns_names      	                 D      	�   ss_names      
                 D      
   
coor_names                         d      
`   node_num_map                    ,      
�   connect1                  	elem_type         EDGE2         P      
�   elem_num_map                    (      @   elem_ss1                          h   side_ss1                          l   elem_ss2                          p   side_ss2                          t   node_ns1                          x   node_ns2                          |   vals_nod_var1                          X      �   vals_nod_var2                          X      �h   name_nod_var                       D      �   name_elem_var                          $      �   vals_elem_var1eb1                          P      ��   elem_var_tab                             �   info_records                      �      �                                         ?ə�����?ٙ�����?�333333?陙����?�      ?�333333?�ffffff?�������?�������@                                                                                                                                                                                                                           left                             right                              left                             right                                                                                                                                                             	   
                                                   	   	   
   
                              	   
         
         h                                p                                  sigma_x                                ####################                                                             # Created by MOOSE #                                                             ####################                                                             ### Command Line Arguments ###                                                   -i                                                                               shearStress.i                                                                                                                                                     ### Version Info ###                                                             Framework Information:                                                           MOOSE version:           git commit 88c412d on 2015-09-18                        PETSc Version:           3.6.0                                                   Current Time:            Fri Oct  2 16:16:07 2015                                Executable Timestamp:    Fri Oct  2 15:16:29 2015                                                                                                                                                                                                  ### Input File ###                                                                                                                                                []                                                                                 name                           =                                                 block                          = INVALID                                         coord_type                     = XYZ                                             fe_cache                       = 0                                               kernel_coverage_check          = 1                                               material_coverage_check        = 1                                               rz_coord_axis                  = Y                                               type                           = FEProblem                                       use_legacy_uo_aux_computation  = INVALID                                         use_legacy_uo_initialization   = INVALID                                         element_order                  = AUTO                                            order                          = AUTO                                            side_order                     = AUTO                                            active_bcs                     = INVALID                                         active_kernels                 = INVALID                                         inactive_bcs                   = INVALID                                         inactive_kernels               = INVALID                                         start                          = 0                                               dimNearNullSpace               = 0                                               dimNullSpace                   = 0                                               error_on_jacobian_nonzero_reallocation = 0                                       petsc_inames                   =                                                 petsc_options                  = INVALID                                         petsc_values                   =                                                 solve                          = 1                                               use_nonlinear                  = 1                                             []                                                                                                                                                                [AuxKernels]                                                                                                                                                        [./sigma_x]                                                                        name                         = AuxKernels/sigma_x                                type                         = ReynoldsShearStress                               block                        = INVALID                                           boundary                     = INVALID                                           component                    = 0                                                 execute_on                   = LINEAR                                            h                            = h                                                 p                            = p                                                 seed                         = 0                                                 use_displaced_mesh           = 0                                                 variable                     = sigma_x                                           vel_surface                  = '(x,y,z)=(      25,        0,        0)'        [../]                                                                          []                                                                                                                                                                [AuxVariables]                                                                                                                                                      [./sigma_x]                                                                        block                        = INVALID                                           family                       = MONOMIAL                                          initial_condition            = INVALID                                           name                         = AuxVariables/sigma_x                              order                        = CONSTANT                                          outputs                      = INVALID                                           initial_from_file_timestep   = 2                                                 initial_from_file_var        = INVALID                                         [../]                                                                          []                                                                                                                                                                [BCs]                                                                                                                                                               [./left]                                                                           boundary                     = left                                              implicit                     = 1                                                 name                         = BCs/left                                          type                         = DirichletBC                                       use_displaced_mesh           = 0                                                 variable                     = p                                                 diag_save_in                 = INVALID                                           save_in                      = INVALID                                           seed                         = 0                                                 value                        = 0                                               [../]                                                                                                                                                             [./left_h]                                                                         boundary                     = left                                              implicit                     = 1                                                 name                         = BCs/left_h                                        type                         = DirichletBC                                       use_displaced_mesh           = 0                                                 variable                     = h                                                 diag_save_in                 = INVALID                                           save_in                      = INVALID                                           seed                         = 0                                                 value                        = 0.001                                           [../]                                                                                                                                                             [./right]                                                                          boundary                     = right                                             implicit                     = 1                                                 name                         = BCs/right                                         type                         = DirichletBC                                       use_displaced_mesh           = 0                                                 variable                     = p                                                 diag_save_in                 = INVALID                                           save_in                      = INVALID                                           seed                         = 0                                                 value                        = 20                                              [../]                                                                                                                                                             [./right_h]                                                                        boundary                     = right                                             implicit                     = 1                                                 name                         = BCs/right_h                                       type                         = DirichletBC                                       use_displaced_mesh           = 0                                                 variable                     = h                                                 diag_save_in                 = INVALID                                           save_in                      = INVALID                                           seed                         = 0                                                 value                        = 0.0008                                          [../]                                                                          []                                                                                                                                                                [Executioner]                                                                      name                           = Executioner                                     type                           = Steady                                          compute_initial_residual_before_preset_bcs = 0                                   l_abs_step_tol                 = -1                                              l_max_its                      = 10000                                           l_tol                          = 1e-05                                           line_search                    = default                                         nl_abs_step_tol                = 1e-50                                           nl_abs_tol                     = 1e-50                                           nl_max_funcs                   = 10000                                           nl_max_its                     = 50                                              nl_rel_step_tol                = 1e-50                                           nl_rel_tol                     = 1e-08                                           no_fe_reinit                   = 0                                               petsc_options                  = INVALID                                         petsc_options_iname            = '-PC_HYPRE_TYPE -PC_TYPE'                       petsc_options_value            = 'hypre boomeramg'                               solve_type                     = PJFNK                                           restart_file_base              =                                                 splitting                      = INVALID                                       []                                                                                                                                                                [Executioner]                                                                      _fe_problem                    = 0x2491ff0                                     []                                                                                                                                                                [Kernels]                                                                                                                                                           [./diff_h]                                                                         name                         = Kernels/diff_h                                    type                         = Diffusion                                         block                        = INVALID                                           diag_save_in                 = INVALID                                           implicit                     = 1                                                 save_in                      = INVALID                                           seed                         = 0                                                 use_displaced_mesh           = 0                                                 variable                     = h                                               [../]                                                                                                                                                             [./diff_p]                                                                         name                         = Kernels/diff_p                                    type                         = Diffusion                                         block                        = INVALID                                           diag_save_in                 = INVALID                                           implicit                     = 1                                                 save_in                      = INVALID                                           seed                         = 0                                                 use_displaced_mesh           = 0                                                 variable                     = p                                               [../]                                                                          []                                                                                                                                                                [Materials]                                                                                                                                                         [./air]                                                                            name                         = Materials/air                                     type                         = ReynoldsIdealGas                                  block                        = 0                                                 boundary                     = INVALID                                           output_properties            = INVALID                                           outputs                      = none                                              p                            = p                                                 seed                         = 0                                                 temp                         = 300                                               use_displaced_mesh           = 0                                               [../]                                                                          []                                                                                                                                                                [Mesh]                                                                             name                           = Mesh                                            displacements                  = INVALID                                         block_id                       = INVALID                                         block_name                     = INVALID                                         boundary_id                    = INVALID                                         boundary_name                  = INVALID                                         construct_side_list_from_node_list = 0                                           ghosted_boundaries             = INVALID                                         ghosted_boundaries_inflation   = INVALID                                         patch_size                     = 40                                              second_order                   = 0                                               skip_partitioning              = 0                                               type                           = GeneratedMesh                                   uniform_refine                 = 0                                               centroid_partitioner_direction = INVALID                                         dim                            = 1                                               distribution                   = DEFAULT                                         elem_type                      = INVALID                                         nemesis                        = 0                                               nx                             = 10                                              ny                             = 1                                               nz                             = 1                                               partitioner                    = default                                         patch_update_strategy          = never                                           xmax                           = 2                                               xmin                           = 0                                               ymax                           = 1                                               ymin                           = 0                                               zmax                           = 1                                               zmin                           = 0                                             []                                                                                                                                                                [Outputs]                                                                          additional_output_on           = INVALID                                         checkpoint                     = 0                                               color                          = 1                                               console                        = 1                                               csv                            = 0                                               dofmap                         = 0                                               execute_on                     = 'INITIAL TIMESTEP_END'                          exodus                         = 1                                               file_base                      = INVALID                                         gmv                            = 0                                               gnuplot                        = 0                                               hide                           = INVALID                                         interval                       = 1                                               name                           = Outputs                                         nemesis                        = 0                                               output_failed                  = 0                                               output_final                   = 0                                               output_if_base_contains        = INVALID                                         output_initial                 = 0                                               output_intermediate            = 1                                               output_on                      = TIMESTEP_END                                    output_timestep_end            = 1                                               print_linear_residuals         = 1                                               print_mesh_changed_info        = 0                                               print_perf_log                 = 0                                               show                           = INVALID                                         solution_history               = 0                                               sync_times                     =                                                 tecplot                        = 0                                               vtk                            = 0                                               xda                            = 0                                               xdr                            = 0                                                                                                                                [./console]                                                                        name                         = Outputs/console                                   type                         = Console                                           additional_execute_on        = INVALID                                           additional_output_on         = INVALID                                           all_variable_norms           = 0                                                 append_displaced             = 0                                                 append_restart               = 0                                                 end_time                     = INVALID                                           execute_elemental_variables  = 1                                                 execute_input                = 1                                                 execute_input_on             = INVALID                                           execute_nodal_variables      = 1                                                 execute_on                   = 'FAILED INITIAL LINEAR NONLINEAR TIMESTEP_... BEGIN TIMESTEP_END'                                                                  execute_postprocessors_on    = 'INITIAL TIMESTEP_END'                            execute_scalar_variables     = 1                                                 execute_scalars_on           = 'INITIAL TIMESTEP_END'                            execute_system_information   = 1                                                 execute_system_information_on = INITIAL                                          execute_vector_postprocessors = 1                                                execute_vector_postprocessors_on = 'INITIAL TIMESTEP_END'                        file_base                    = INVALID                                           fit_mode                     = ENVIRONMENT                                       hide                         = INVALID                                           interval                     = 1                                                 linear_residual_dt_divisor   = 1000                                              linear_residual_end_time     = INVALID                                           linear_residual_start_time   = INVALID                                           linear_residuals             = 0                                                 max_rows                     = 15                                                nonlinear_residual_dt_divisor = 1000                                             nonlinear_residual_end_time  = INVALID                                           nonlinear_residual_start_time = INVALID                                          nonlinear_residuals          = 0                                                 outlier_multiplier           = '0.8 2'                                           outlier_variable_norms       = 1                                                 output_failed                = 0                                                 output_file                  = 0                                                 output_final                 = 0                                                 output_if_base_contains      =                                                   output_initial               = 0                                                 output_intermediate          = 1                                                 output_linear                = 0                                                 output_nonlinear             = 0                                                 output_on                    = TIMESTEP_END                                      output_postprocessors        = 1                                                 output_screen                = 1                                                 output_timestep_end          = 1                                                 padding                      = 4                                                 perf_header                  = INVALID                                           perf_log                     = 0                                                 print_mesh_changed_info      = 0                                                 scientific_time              = 0                                                 setup_log                    = INVALID                                           setup_log_early              = 0                                                 show                         = INVALID                                           show_multiapp_name           = 0                                                 solve_log                    = INVALID                                           start_time                   = INVALID                                           sync_only                    = 0                                                 sync_times                   =                                                   system_info                  = 'AUX EXECUTION FRAMEWORK MESH NONLINEAR'          time_precision               = INVALID                                           time_tolerance               = 1e-14                                             use_displaced                = 0                                                 verbose                      = 0                                               [../]                                                                                                                                                             [./exodus]                                                                         name                         = Outputs/exodus                                    type                         = Exodus                                            additional_execute_on        = INVALID                                           additional_output_on         = INVALID                                           append_displaced             = 0                                                 append_oversample            = 0                                                 elemental_as_nodal           = 0                                                 end_time                     = INVALID                                           execute_elemental_on         = INVALID                                           execute_elemental_variables  = 1                                                 execute_input                = 1                                                 execute_input_on             = INITIAL                                           execute_nodal_on             = INVALID                                           execute_nodal_variables      = 1                                                 execute_on                   = 'INITIAL TIMESTEP_END'                            execute_postprocessors_on    = INVALID                                           execute_scalar_variables     = 1                                                 execute_scalars_on           = INVALID                                           execute_system_information   = 1                                                 execute_vector_postprocessors = 1                                                file                         = INVALID                                           file_base                    = INVALID                                           hide                         = INVALID                                           interval                     = 1                                                 linear_residual_dt_divisor   = 1000                                              linear_residual_end_time     = INVALID                                           linear_residual_start_time   = INVALID                                           linear_residuals             = 0                                                 nonlinear_residual_dt_divisor = 1000                                             nonlinear_residual_end_time  = INVALID                                           nonlinear_residual_start_time = INVALID                                          nonlinear_residuals          = 0                                                 output_failed                = 0                                                 output_final                 = 0                                                 output_if_base_contains      =                                                   output_initial               = 0                                                 output_intermediate          = 1                                                 output_linear                = 0                                                 output_material_properties   = 0                                                 output_nonlinear             = 0                                                 output_on                    = TIMESTEP_END                                      output_postprocessors        = 1                                                 output_timestep_end          = 1                                                 oversample                   = 0                                                 padding                      = 3                                                 position                     = INVALID                                           refinements                  = 0                                                 scalar_as_nodal              = 0                                                 sequence                     = INVALID                                           show                         = INVALID                                           show_material_properties     = INVALID                                           start_time                   = INVALID                                           sync_only                    = 0                                                 sync_times                   =                                                   time_tolerance               = 1e-14                                             use_displaced                = 0                                               [../]                                                                          []                                                                                                                                                                [Variables]                                                                                                                                                         [./h]                                                                              block                        = INVALID                                           eigen                        = 0                                                 family                       = LAGRANGE                                          initial_condition            = INVALID                                           name                         = Variables/h                                       order                        = FIRST                                             outputs                      = INVALID                                           scaling                      = 1                                                 initial_from_file_timestep   = 2                                                 initial_from_file_var        = INVALID                                         [../]                                                                                                                                                             [./p]                                                                              block                        = INVALID                                           eigen                        = 0                                                 family                       = LAGRANGE                                          initial_condition            = INVALID                                           name                         = Variables/p                                       order                        = FIRST                                             outputs                      = INVALID                                           scaling                      = 1                                                 initial_from_file_timestep   = 2                                                 initial_from_file_var        = INVALID                                         [../]                                                                          []                                                                                                                                                                                                                                                                                                                                                        ?�      ?PbM��?Pj��^?OuMUs?N�J�,?N%�����?M}�H˜?L���8�U?L.3��?K�nC�y�?Jި�c^|?J6��C5        @      @     @     @      @$     @(     @,     @0     @2     @4     ?ܙ�G�?�-j8��A?��]�;i?�hqX��?�ɐGՆ?߿.)׭�?�;[[$v�?��{+@��?� G-K6z?�j'�