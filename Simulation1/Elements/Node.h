#ifndef ELEMENTS_NODE_H
#define ELEMENTS_NODE_H

#include "Vector.h"
#include "Body.h"
#include<list>

class Node {
public:
    int count;
    double radius;
    Vector center;
    std::list<Body> bodies;

    Body pseudobody;

    Node *NW;
    Node *NE;
    Node *SW;
    Node *SE;

    Node();
    Node(const Node &other);
    //Node(const int &Count, const double &Radius, const Vector &Center, const std::list<Body> &Bodies, const Body &Pseudobody);
    Node(const double &Radius, const Vector &Center, const std::list<Body> &Bodies);

    static Body findMassCenter(const Node &node);
    void traverse(void (*foo)(const Node &node)) const;
};

void printNode(const Node &node);


#endif //ELEMENTS_NODE_H
