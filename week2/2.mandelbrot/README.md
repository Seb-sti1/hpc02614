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

| nb thread | time  |
|-----------|-------|
| 1         | 7.76  |
| 2         | 6.38  |
| 4         | 6.325 |
| 8         | 4.81  |
| 16        | 4.113 |

## Does your code scale? How can you check this?

It scales very poorly

## What do you have to change to make the code scale?

### schedule(guided, 100)

| nb thread | time  |
|-----------|-------|
| 1         | 7.744 |
| 2         | 6.383 |
| 4         | 6.306 |
| 8         | 4.831 |
| 16        | 4.044 |

### schedule(dynamic)

| nb thread | time  |
|-----------|-------|
| 1         | 7.76  |
| 2         | 5.475 |
| 4         | 4.217 |
| 8         | 3.683 |
| 16        | 3.366 |