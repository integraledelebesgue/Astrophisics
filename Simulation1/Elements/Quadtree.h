#ifndef ELEMENTS_QUADTREE_H
#define ELEMENTS_QUADTREE_H
#include "Vector.h"
#include "Body.h"
#include "Node.h"
#include<stack>


void qualifyBodies(Node *curr, std::list<Body> &NW, std::list<Body> &NE, std::list<Body> &SW, std::list<Body> &SE);
void constructTree(Node &root);

#endif //ELEMENTS_QUADTREE_H
