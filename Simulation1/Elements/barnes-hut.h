#ifndef ELEMENTS_BARNES_HUT_H
#define ELEMENTS_BARNES_HUT_H

#include  "Vector.h"

double **perform(double **state, int count, double radius, double accuracy);
void vectorToArr(double **arr, Vector *vectors, int count);
void printArr(double **arr, int count);

#endif //ELEMENTS_BARNES_HUT_H
