#!/bin/bash
#BSUB -J sleeper
#BSUB -o sleeper_%J.out
#BSUB -q hpcintro
#BSUB -W 2
##BSUB -B
##BSUB -N
##BSUB -n 16
##BSUB -R "span[hosts=1]"
##BSUB -R "select[model == XeonE5_2650v4]"
#BSUB -R "rusage[mem=512MB]"

#lscpu
/bin/sleep 60