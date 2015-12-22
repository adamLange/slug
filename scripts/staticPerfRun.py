import subprocess
import numpy as np
import os
import pandas as pd
from time import localtime
from hashlib import md5

# input file
inputFile = 'ex01.i'
numProc = 6

# mesh files
#mesh_array = [('filename',float integrated_area, floathole_area)]
mesh_array = [('mesh1',-1,-1)]

# control for h, the film thickness
min_h = 10e-6 #m
max_h = 1e-3 #m
n_h = 10

# controls for ps, the air bearing supply pressure
ps_min = 10e3 #Pa
ps_max = 10e3 #Pa
n_ps = 1

# controls for p_amb 
pamb_min = 100.0
pamb_max = 100.0
n_pamb = 1

# controls for T, the isothermal temperature in the film
T_min = 300.0
T_max = 300.0
n_T = 1

# controls for sliding velocity (x component)
min_v = 0
max_v = 0
n_v = 1

#controls for alpha
min_alpha = 0
max_alpha = 0
n_alpha = 1

# in nested for loops, create the slug commands to execute

h_array = np.linspace(min_h,max_h,n_h)
ps_array = np.linspace(ps_min,ps_max,n_ps)
pamb_array = np.linspace(pamb_min,pamb_max,n_pamb)
T_array = np.linspace(T_min,T_max,n_T)
v_array = np.linspace(min_v,max_v,n_v)
alpha_array = np.linspace(min_alpha,max_alpha,n_alpha)

commands = []

for mesh in mesh_array:
  for h in h_array:
    for ps in ps_array:
      for pamb in pamb_array:
        for T in T_array:
          for v in v_array:
            for alpha in alpha_array:
              cmd_str = (
                  'mpiexec -n {} slug-opt -i {} '.format(numProc,inputFile)
                  +'Mesh/file={} '.format(mesh[0])
                  +'AuxKernels/h/h={} '.format(h)
                  +'BCs/inlet/value={} '.format(ps)
                  +'BCs/perimeter/value={} '.format(pamb)
                  +'GlobalParams/vel_surface=\'{} 0 0\' '.format(v)
                  +'Kernels/Pressure/v={} '.format(v)
                  +'AuxKernels/h/alpha={} '.format(alpha)
                  +'--show-input '
                  +'--no-color '
                  )
              df = pd.DataFrame({
                  'hash':[md5(str(localtime())+str(h)+str(ps)+str(pamb)+str(T)+str(v)+str(alpha)).hexdigest()],
                  'mesh':[mesh[0]],
                  'film_area':[mesh[1]],
                  'inlet_area':[mesh[2]],
                  'h':[h],
                  'ps':[ps],
                  'pamb':[pamb],
                  'T':[T],
                  'v':[v],
                  'alpha':[alpha]
                })
              commands.append([cmd_str,df])

# divy out the jobs (each job is a mpi job, and multiple 
# mpi jobs can go at once.)

num_commands = len(commands)
for i in range(num_commands):
  hsh = commands[i][1]['hash'].iloc[0]
  cmd = commands[i][0]\
    +'Outputs/exodus/file_base=exodus_{} '.format(hsh)\
    +'Outputs/csv/file_base=postprocessor_{}'.format(hsh)\
    +'>&1 > output_{}.log'.format(hsh)

  print(
    '\nBeginning solve {} of {}\nhash: {}\n'.format((i+1),num_commands,hsh)
    +cmd
  )
  commands[i][1].to_csv('./indep_{}.csv'.format(hsh))
  os.system(cmd)

