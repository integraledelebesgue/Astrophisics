#ifndef NODE_H
#define NODE_H

#include<list>
#include<array>
#include<vector>
#include "Body.h"

using namespace std;


class Node{
public:
    Vector center;
    list<Body> bodies;
    double radius;
    Body mass_center;
    array<Node *, 8> children;

    Node();
    Node(const Vector &, const double &, const list<Body> &);
    bool trivial();
    bool isLeaf();
    friend void divideNode(Node &, vector<Node *> processed);
};

void divideNode(Node &, vector<Node *> processed);


#endif