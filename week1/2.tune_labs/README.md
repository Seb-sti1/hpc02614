Lab exercise 'data structure'
----------------------------

Imagine you have a 3-dimensional box with NUM_OF_PARTS particles, that are
randomly distributed within the box of size 1x1x1 (in arbitrary units).

Use the template files in this directory,

Makefile
data.h
distance.h
distcheck.h
init_data.c
init_data.h
main.c
testsource
xtime.c
xtime.h

to write two programs, with two different data structure layouts (as
shown in the lecture).


Part 1:
-------

You need to provide two subroutines, distance(...) and distcheck(...),
for both types of data structures.  In distance(...) you should calculate
the distance of each particle to the point (0,0,0) and the total sum
of all distances.  In distcheck(...), you sum up only the distances,
i.e. you should only access the distance part of your data.  Print both
results during the test phase to have a check for consistency.

You need also to provide a measure for the number of floating point
operations in each subroutine, counted per particle.  Those numbers,
DIST_FLOP and CHECK_FLOP will be used in main.c to calculate the Mflop/s
numbers.  Hint:  For the sake of simplicity, assume that the sqrt()
function counts 4 FLOPs.

The program takes two command line arguments: the number of loops and
the number of particles.  The first one has a default value of 1, the
latter the compiled in default NUM_OF_PARTS (see data.h).  With those
two parameters, you can control the size (memory footprint) and runtime
of your problem.

Both programs print out 5 values (on a single line):

    memory footprint in kB
    Mflop/s of distance(...)
    Mflop/s of distcheck(...)
    Mflop/s of total program
    runtime in secs

You can check those values easily:  For a given memory footprint, the
Mflop/s numbers shouldn't vary much when varying the number of loops,
and the runtime in secs should correspond approximately to the value
you can obtain with the 'time program ...' command.

During the test phase, you can undefine the -DDATA_ANALYSIS in the
Makefile, to get a more verbose output.


Part 2:
-------

Run a series of experiments for both programs, e.g. for 2000 ... 3000000
particles (choose the stepsize in a clever way) and 1000 loops.  Plot the
runtimes and Mflop/s numbers versus the memory footprint, as shown in
the lecture notes.  Under which conditions is one version faster, when
the other one?


Part 3:
-------
(Wait with this part, until the tools have been presented in the lecture!)

Use the gprofng performance analyzer to find out more about the program.  
Use memory footprint values from part 2, that are below and above the
level 2 cache size (how can you tell from the plots in part 2?), to do
those experiments.  

Note: you need to load the gprofng module, first!

a) run a 'standard' experiment with gprofng and look for the 'hot
   spots' in both programs

b) use the hardware counter profiling, to compare e.g. 
       - L1 cache hits (dch) and L1 cache misses (dcm)
       - L2 cache hits (l2h) and L2 cache misses (l2m) 
       - other relevant counters (optional)
   for both programs and different system sizes (memory footprints).


```
$ gprofng collect app -h dch -h dcm -h l2h -h l2m ./aos.gcc 4000 4000
$ gprofng display text aos.lessl1.er/
(gp-display-text) func
Functions sorted by metric: Exclusive Total CPU Time

Excl. Total   Incl. Total   Excl. L1         Excl. L1        Excl. L2 Cache  Excl. L2       Name
CPU           CPU           D-cache Hits     D-cache Misses  Hits            Cache Misses
 sec.      %   sec.      %                %               %               %         %
0.100 100.00  0.100 100.00  40040007 100.00  6402007 100.00  6402005 100.00  0   0.         <Total>
0.080  80.00  0.080  80.00  40040007 100.00        0   0.          0   0.    0   0.         distance
0.020  20.00  0.020  20.00         0   0.    6402007 100.00  6402005 100.00  0   0.         distcheck
0.      0.    0.100 100.00         0   0.          0   0.          0   0.    0   0.         __libc_start_call_main
0.      0.    0.100 100.00         0   0.          0   0.          0   0.    0   0.         main
```

```
$ gprofng collect app -h dch -h dcm -h l2h -h l2m ./aos.gcc 4000 40000
$ gprofng display text aos.morel1.er/
(gp-display-text) func    
Functions sorted by metric: Exclusive Total CPU Time

Excl. Total   Incl. Total   Excl. L1 D-cache  Excl. L1         Excl. L2 Cache   Excl. L2 Cache    Name
CPU           CPU           Hits              D-cache Misses   Hits             Misses
sec.      %   sec.      %                 %                %                %                %
1.001 100.00  1.001 100.00  470470051 100.00  99231034 100.00  12804004 100.00  87087094 100.00   <Total>
0.781  78.00  0.781  78.00  470470051 100.00   3201000   3.23         0   0.           0   0.     distance
0.190  19.00  0.190  19.00          0   0.    96030034  96.77  12804004 100.00  87087094 100.00   distcheck
0.030   3.00  0.030   3.00          0   0.           0   0.           0   0.           0   0.     getrusage
0.      0.    1.001 100.00          0   0.           0   0.           0   0.           0   0.     __libc_start_call_main
0.      0.    1.001 100.00          0   0.           0   0.           0   0.           0   0.     main
0.      0.    0.030   3.00          0   0.           0   0.           0   0.           0   0.     xtime
```

```
$ gprofng collect app -h dch -h dcm -h l2h -h l2m ./soa.gcc 4000 4000
$ gprofng display text soa.lessl1.er/
(gp-display-text) func
Functions sorted by metric: Exclusive Total CPU Time

Excl. Total   Incl. Total   Excl. L1         Excl. L1        Excl. L2    Excl. L2       Name
CPU           CPU           D-cache Hits     D-cache Misses  Cache Hits  Cache Misses
 sec.      %   sec.      %                %         %               %           %
0.100 100.00  0.100 100.00  60060009 100.00  0   0.          0   0.      0   0.         <Total>
0.060  60.00  0.060  60.00  30030002  50.00  0   0.          0   0.      0   0.         distance
0.020  20.00  0.020  20.00         0   0.    0   0.          0   0.      0   0.         getrusage
0.010  10.00  0.010  10.00  30030007  50.00  0   0.          0   0.      0   0.         distcheck
0.010  10.00  0.030  30.00         0   0.    0   0.          0   0.      0   0.         xtime
0.      0.    0.100 100.00         0   0.    0   0.          0   0.      0   0.         __libc_start_call_main
0.      0.    0.100 100.00         0   0.    0   0.          0   0.      0   0.         main
```

```
$ gprofng collect app -h dch -h dcm -h l2h -h l2m ./soa.gcc 4000 4000
$ gprofng display text soa.morel1.er/
(gp-display-text) func
Functions sorted by metric: Exclusive Total CPU Time

Excl. Total   Incl. Total   Excl. L1 D-cache  Excl. L1        Excl. L2 Cache  Excl. L2       Name
CPU           CPU           Hits              D-cache Misses  Hits            Cache Misses
 sec.      %   sec.      %                 %               %               %         %
0.961 100.00  0.961 100.00  620620069 100.00  9603006 100.00  6402002 100.00  0   0.         <Total>
0.761  79.17  0.761  79.17  470470009  75.81  9603006 100.00  6402002 100.00  0   0.         distance
0.170  17.71  0.170  17.71  150150060  24.19        0   0.          0   0.    0   0.         distcheck
0.020   2.08  0.020   2.08          0   0.          0   0.          0   0.    0   0.         getrusage
0.010   1.04  0.010   1.04          0   0.          0   0.          0   0.    0   0.         munmap
0.      0.    0.961 100.00          0   0.          0   0.          0   0.    0   0.         __libc_start_call_main
0.      0.    0.010   1.04          0   0.          0   0.          0   0.    0   0.         free
0.      0.    0.961 100.00          0   0.          0   0.          0   0.    0   0.         main
0.      0.    0.020   2.08          0   0.          0   0.          0   0.    0   0.         xtime
```

