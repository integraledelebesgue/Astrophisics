#ifndef ELEMENTS_PHYSICS_H
#define ELEMENTS_PHYSICS_H

double distance(const Vector &v1, const Vector &v2);
Vector direction(const Vector &a, const Vector &b);
Vector computeForce(const Body &particle, const Body &source);
void computeForces(const Node &root, Vector result[]);
Vector computeResultantForce(const Node &root, const Body &body);

#endif //ELEMENTS_PHYSICS_H
