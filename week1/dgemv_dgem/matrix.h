//
// Created by seb-sti1 on 06/01/25.
//

void displayVector(double *matrix, unsigned long n);

void displayMatrix(double **matrix, unsigned long n, unsigned long m);

double *randomVector(unsigned long n);

double **randomMatrix(unsigned long n, unsigned long m);

double *emptyVector(unsigned long n);

double **emptyMatrix(unsigned long n, unsigned long m);

void freeMatrix(double **A, unsigned long n);

void add(double **C, double **A, double **B, unsigned long n, unsigned long m);

void productMatrixWithVector(double *c, double **A, double *b, unsigned long n, unsigned long m);

void multiplication(double **C, double **A, double **B,
                    unsigned long m, unsigned long k, unsigned long n);