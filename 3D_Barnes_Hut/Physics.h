#ifndef PHYSICS_H
#define PHYSICS_H
#include<vector>
#include<array>
#include "Vector.h"
#include "Body.h"
#include "Node.h"

using namespace std;

void computeResultants(Node &root, vector<array<double, 3>> &results, double accuracy);
Vector getResultantForce(const Node &root, Body &body, double threshold);

#endif