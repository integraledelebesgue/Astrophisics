#ifndef QUADTREE_H
#define QUADTREE_H

#include "Body.h"
#include "Node.h"
#include<stack>
#include<vector>

using namespace std;


void buildTree(Node &root, stack<Node *> &memory_stack);

#endif