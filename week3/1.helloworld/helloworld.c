//
// Created by seb-sti1 on 20/01/25.
//
#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

#pragma omp target teams parallel \
num_teams(4) thread_limit(64)
  {
    int global_tid = omp_get_team_num() * omp_get_num_threads() + omp_get_thread_num();
    if (global_tid == 100) { // will segfault when reached
      int *a = (int *) 0x10000;
      *a = 0;
    }
    printf("Hello world! I’m thread %d out of %d in team %d. My global thread id is %d out of %d.\n",
           omp_get_thread_num(),
           omp_get_num_threads(),
           omp_get_team_num(),
           omp_get_team_num() * omp_get_num_threads() + omp_get_thread_num(),
           omp_get_num_teams() * omp_get_num_threads());
  } // end target teams parallel
  return (0);
}