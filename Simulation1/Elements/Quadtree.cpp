#include "Vector.h"
#include "Body.h"
#include "Node.h"
#include "Quadtree.h"
#include<stack>
#include <iostream>

using namespace  std;

void constructTree(Node &root){
    stack<Node *> Stack;
    Node *curr;

    std::list<Body> NW, NE, SW, SE;

    Stack.push(&root);

    while(!Stack.empty()){
        cout << "In loop..";
        curr = Stack.top();
        Stack.pop();

        qualifyBodies(curr, NW, NE, SW, SE);

        if(!NW.empty()){
            curr->NW = new Node(curr->radius/2, curr->center - Vector(curr->radius/4, (-1)*curr->radius/4), NW);
            if(NW.size() > 1) Stack.push(curr->NW);
            NW.clear();
        }

        if(!NE.empty()){
            curr->NE = new Node(curr->radius/2, curr->center + Vector(curr->radius/4, curr->radius/4), NE);
            if(NE.size() > 1) Stack.push(curr->NE);
            NE.clear();
        }

        if(!SW.empty()){
            curr->SW = new Node(curr->radius/2, curr->center - Vector(curr->radius/4, curr->radius/4), SW);
            if(SW.size() > 1) Stack.push(curr->SW);
            SW.clear();
        }

        if(!SE.empty()){
            curr->SE = new Node(curr->radius/2, curr->center - Vector(curr->radius/4, curr->radius/4), SE);
            if(SE.size() > 1) Stack.push(curr->SE);
            SE.clear();
        }
    }
}

void qualifyBodies(Node *curr, list<Body> &NW, list<Body> &NE, list<Body> &SW, list<Body> &SE){
    Vector position;

    cout << "Qualifying node: " << endl;
    printNode(*curr);
    cout << endl;

    for(const auto &body : curr->bodies){
        position = curr->center - body.position;

        if(position.x < 0 && position.y > 0) NW.emplace_back(body);
        else if(position.x > 0 && position.y > 0) NE.emplace_back(body);
        else if(position.x < 0 && position.y < 0) SW.emplace_back(body);
        else if(position.x > 0 && position.y < 0) SE.emplace_back(body);
    }
}