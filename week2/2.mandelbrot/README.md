## Generate the serial version by using 'make', and run it. This should generate a PNG file with the image of the Mandelbrot set!

```
time ./mandelbrot 

real    0m7.720s
user    0m7.607s
sys     0m0.083s
```

Image size 4601 x 4601

## Parallelize the generation of the Mandelbrot set using OpenMP work sharing constructs.

_Check the runtimes for different numbers of threads._

_Note: Dumping the image to the disk takes a fixed time, independent of the number of threads. You can comment the
call to the image writer in the code, to avoid
this._

