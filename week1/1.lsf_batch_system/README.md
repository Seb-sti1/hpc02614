## Write a simple job script, like the one shown in the lecture and submit

```shell
$ bsub < sleeper.sh
```

### Check the status with bstat and/or bjobs. Use ’man bjobs’, to get information about the options.

```shell
$ bjobs
JOBID      USER    QUEUE      JOB_NAME   SLOTS STAT  START_TIME   TIME_LEFT  
23518690   s232496 hpcintro   sleeper        1 RUN   Jan  6 13:59 00:01:32 L
```

### You can add a walltime limit to the script. Can you see that limit in the bstat or the bjobs output?

```shell
$ bjobs
JOBID      USER    QUEUE      JOB_NAME   SLOTS STAT  START_TIME   TIME_LEFT  
23518690   s232496 hpcintro   sleeper        1 RUN   Jan  6 13:59 00:01:32 L
$ bstat
JOBID      USER    QUEUE      JOB_NAME   NALLOC STAT  START_TIME      ELAPSED
23518690   s232496 hpcintro   sleeper         1 RUN   Jan  6 13:59    0:00:28
```

#### in the bstat output

Can see the duration seems the beginning not the time left

#### in the bjobs output

Can see the time limit

## Write a job script that sends you notifications when the job starts and ends - see 'man bsub' for the details. Take a look at the job summary, i.e. which information can you retrieve from that?

Add following to receive on dtu email

```
#BSUB -B
#BSUB -N
```

```shell
$ bsub < sleeper.sh
Job <23518880> is submitted to queue <hpcintro>.
```

The summary is

```
Job <sleeper> was submitted from host <n-62-30-1> by user <s232496> in cluster <dcc> at Mon Jan  6 14:22:26 2025
Job was executed on host(s) <n-62-21-74>, in queue <hpcintro>, as user <s232496> in cluster <dcc> at Mon Jan  6 14:22:28 2025
</zhome/3c/8/202539> was used as the home directory.
</zhome/3c/8/202539> was used as the working directory.
Started at Mon Jan  6 14:22:28 2025
Terminated at Mon Jan  6 14:23:28 2025
Results reported at Mon Jan  6 14:23:28 2025

Your job looked like:

------------------------------------------------------------
# LSBATCH: User input
#!/bin/bash
#BSUB -J sleeper
#BSUB -o sleeper_%J.out
#BSUB -q hpcintro
#BSUB -W 2
#BSUB -B
#BSUB -N
#BSUB -R "rusage[mem=512MB]"

/bin/sleep 60

------------------------------------------------------------

Successfully completed.

Resource usage summary:

    CPU time :                                   0.48 sec.
    Max Memory :                                 6 MB
    Average Memory :                             6.00 MB
    Total Requested Memory :                     512.00 MB
    Delta Memory :                               506.00 MB
    Max Swap :                                   -
    Max Processes :                              4
    Max Threads :                                5
    Run time :                                   60 sec.
    Turnaround time :                            62 sec.

Read file <sleeper_23518943.out> for stdout and stderr output of this job.
```

### To test, increase the period in the sleep command to be longer than the walltime limit, and submit the job again. What happens?

With a sleep of 90 and a walltime of 1min

## The default 'hpc' queue has nodes of different type, e.g. CPUs. The CPU type can be requested as a feature in a command script

### Use the "nodestat" command to check which CPU types are available in the 'hpc' queue, and then submit a job script that requests one of the types. See the "Batch Jobs under LSF 10" webpage for information how to do that.

```shell
$ nodestat -F hpcintro | awk '{ print $5 }' | uniq
Model
XeonGold6226R
XeonGold6342
XeonGold6226R
EPYC9554
XeonPlatinum8462Y
XeonE5_2650v4
XeonE5_2660v3
XeonGold6142
XeonGold6126
```

by adding `#BSUB -R "select[model == XeonE5_2650v4]"` it is possible
to request a specific cpu

### Add  the  necessary  commands  to  your  job  script, to  print  the  CPU  type - and check in the job output that your job did indeed run on a node with the requested feature

By adding `lscpu` in the script it is possible to confirm that the correct cpu is running the program

```shell
$ cat sleeper_23520406.out | grep "Model name"
Model name:                           Intel(R) Xeon(R) CPU E5-2650 v4 @ 2.20GHz
```

## Write a job script that requests 1 node and 4/16/32 cores. How can you achieve that?

Add the following to the script

```
#BSUB -n 4
#BSUB -R "span[hosts=1]"
```

It runs fine with 4, 16, 32 cores