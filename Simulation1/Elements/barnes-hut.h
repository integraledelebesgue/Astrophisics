#ifndef ELEMENTS_BARNES_HUT_H
#define ELEMENTS_BARNES_HUT_H

#include<vector>
#include  "Vector.h"
#include<stack>
#include "memory.h"


std::vector<std::vector<double>> getForces(const std::vector<std::vector<double>> &state, int count, double radius, double accuracy);

#endif //ELEMENTS_BARNES_HUT_H
