To compile `gcc -fopenmp -o prime prime.c -lm`

```
n-62-30-4(s232496) $ OMP_NUM_THREADS=8 ./prime 
# of prime numbers between 2 and 200000: 12092
n-62-30-4(s232496) $ OMP_NUM_THREADS=8 ./prime 
# of prime numbers between 2 and 200000: 12077
n-62-30-4(s232496) $ OMP_NUM_THREADS=8 ./prime 
# of prime numbers between 2 and 200000: 12003
n-62-30-4(s232496) $ OMP_NUM_THREADS=8 ./prime 
# of prime numbers between 2 and 200000: 12107
n-62-30-4(s232496) $ OMP_NUM_THREADS=8 ./prime 
# of prime numbers between 2 and 200000: 12112
```

The sanitize option `-fopenmp -fsanitize=thread -lomp`

Gives 
```
n-62-30-4(s232496) $ OMP_NUM_THREADS=8 ./prime 
Warning: please export TSAN_OPTIONS='ignore_noninstrumented_modules=1' to avoid false positive reports from the OpenMP runtime!
==================
WARNING: ThreadSanitizer: data race (pid=2451297)
  Atomic read of size 1 at 0x7b6c00002880 by main thread:
    #0 pthread_mutex_lock <null> (libtsan.so.0+0x54a98)
    #1 void __kmp_resume_template<kmp_flag_64<false, true> >(int, kmp_flag_64<false, true>*) [clone .llvm.2083359973855901367] <null> (libomp.so+0xb2f61)

  Previous write of size 1 at 0x7b6c00002880 by thread T4:
    #0 pthread_mutex_init <null> (libtsan.so.0+0x4d071)
    #1 __kmp_suspend_initialize_thread <null> (libomp.so+0xb1971)

  Location is heap block of size 1568 at 0x7b6c00002300 allocated by main thread:
    #0 malloc <null> (libtsan.so.0+0x32dd7)
    #1 __kmp_allocate_thread <null> (libomp.so+0x46927)

  Thread T4 (tid=2451302, running) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x61748)
    #1 __kmp_create_worker <null> (libomp.so+0xb01fa)

SUMMARY: ThreadSanitizer: data race (/lib64/libtsan.so.0+0x54a98) in pthread_mutex_lock
==================
==================
WARNING: ThreadSanitizer: data race (pid=2451297)
  Atomic read of size 1 at 0x7b6c00003d80 by thread T4:
    #0 pthread_mutex_lock <null> (libtsan.so.0+0x54a98)
    #1 void __kmp_resume_template<kmp_flag_64<false, true> >(int, kmp_flag_64<false, true>*) [clone .llvm.2083359973855901367] <null> (libomp.so+0xb2f61)

  Previous write of size 1 at 0x7b6c00003d80 by thread T7:
    #0 pthread_mutex_init <null> (libtsan.so.0+0x4d071)
    #1 __kmp_suspend_initialize_thread <null> (libomp.so+0xb1971)

  Location is heap block of size 1568 at 0x7b6c00003800 allocated by main thread:
    #0 malloc <null> (libtsan.so.0+0x32dd7)
    #1 __kmp_allocate_thread <null> (libomp.so+0x46927)

  Thread T4 (tid=2451302, running) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x61748)
    #1 __kmp_create_worker <null> (libomp.so+0xb01fa)

  Thread T7 (tid=2451305, running) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x61748)
    #1 __kmp_create_worker <null> (libomp.so+0xb01fa)

SUMMARY: ThreadSanitizer: data race (/lib64/libtsan.so.0+0x54a98) in pthread_mutex_lock
==================
==================
WARNING: ThreadSanitizer: data race (pid=2451297)
  Write of size 4 at 0x7fffcbcc1798 by main thread:
    #0 main._omp_fn.0 <null> (prime+0x4014c6)
    #1 GOMP_parallel <null> (libomp.so+0xbd7f8)
    #2 main <null> (prime+0x40139d)

  Previous write of size 4 at 0x7fffcbcc1798 by thread T1:
    #0 main._omp_fn.0 <null> (prime+0x4014c6)
    #1 __kmp_GOMP_microtask_wrapper(int*, int*, void (*)(void*), void*) <null> (libomp.so+0xb6bda)
    #2 main <null> (prime+0x40139d)

  Location is stack of main thread.

  Location is global '<null>' at 0x000000000000 ([stack]+0x000000004798)

  Thread T1 (tid=2451299, running) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x61748)
    #1 __kmp_create_worker <null> (libomp.so+0xb01fa)

SUMMARY: ThreadSanitizer: data race (/zhome/3c/8/202539/hpc02614/week2/2.prime/prime+0x4014c6) in main._omp_fn.0
==================
==================
WARNING: ThreadSanitizer: data race (pid=2451297)
  Read of size 4 at 0x7fffcbd84a38 by thread T3:
    #0 main._omp_fn.0 <null> (prime+0x4014a5)
    #1 __kmp_GOMP_microtask_wrapper(int*, int*, void (*)(void*), void*) <null> (libomp.so+0xb6bda)
    #2 main <null> (prime+0x40139d)

  Previous write of size 4 at 0x7fffcbd84a38 by main thread:
    #0 main._omp_fn.0 <null> (prime+0x4014fd)
    #1 GOMP_parallel <null> (libomp.so+0xbd7f8)
    #2 main <null> (prime+0x40139d)

  Location is stack of main thread.

  Location is global '<null>' at 0x000000000000 ([stack]+0x0000000c7a38)

  Thread T3 (tid=2451301, running) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x61748)
    #1 __kmp_create_worker <null> (libomp.so+0xb01fa)

SUMMARY: ThreadSanitizer: data race (/zhome/3c/8/202539/hpc02614/week2/2.prime/prime+0x4014a5) in main._omp_fn.0
==================
==================
WARNING: ThreadSanitizer: data race (pid=2451297)
  Write of size 4 at 0x7fffcbcc1854 by thread T1:
    #0 main._omp_fn.0 <null> (prime+0x4014c6)
    #1 __kmp_GOMP_microtask_wrapper(int*, int*, void (*)(void*), void*) <null> (libomp.so+0xb6bda)
    #2 main <null> (prime+0x40139d)

  Previous write of size 4 at 0x7fffcbcc1854 by thread T2:
    #0 main._omp_fn.0 <null> (prime+0x4014c6)
    #1 __kmp_GOMP_microtask_wrapper(int*, int*, void (*)(void*), void*) <null> (libomp.so+0xb6bda)
    #2 main <null> (prime+0x40139d)

  Location is stack of main thread.

  Location is global '<null>' at 0x000000000000 ([stack]+0x000000004854)

  Thread T1 (tid=2451299, running) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x61748)
    #1 __kmp_create_worker <null> (libomp.so+0xb01fa)

  Thread T2 (tid=2451300, running) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x61748)
    #1 __kmp_create_worker <null> (libomp.so+0xb01fa)

SUMMARY: ThreadSanitizer: data race (/zhome/3c/8/202539/hpc02614/week2/2.prime/prime+0x4014c6) in main._omp_fn.0
==================
```

```
n-62-30-4(s232496) $ detect_dr ./prime 
Archer detected OpenMP application with TSan, supplying OpenMP synchronization semantics
# of prime numbers between 2 and 200000: 17984
SUMMARY: ThreadSanitizer: data race (/zhome/3c/8/202539/hpc02614/week2/2.prime/prime+0x4014a5) in main._omp_fn.0
ThreadSanitizer: reported 1 warnings
Full datarace detection report written to prime_250114_140113.ddr
~/hpc02614/week2/2.prime
```

