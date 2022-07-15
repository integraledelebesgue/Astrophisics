#ifndef NODE_H
#define NODE_H

#include<list>
#include<array>
#include "Body.h"

using namespace std;


class Node{
private:
    array<double, 3> center;
    double radius;
    Body mass_center;
    list<Body> bodies;
    array<Node *, 8> children;

public:
    Node();
    Node(const array<double, 3> &, const double &, const list<Body> &);
    void findMassCenter(Node &);
    friend array<Node *, 8> divideNode(const Node &);
};

array<Node *, 8> divideNode(const Node &);

#endif