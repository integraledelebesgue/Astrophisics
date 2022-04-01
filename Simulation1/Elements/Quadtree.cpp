#include "Vector.h"
#include "Body.h"
#include "Node.h"
#include "Quadtree.h"
#include "memory.h"
#include<stack>
#include <iostream>

using namespace  std;

void constructTree(Node &root){
    stack<Node *> Stack;
    Node *curr;

    std::list<Body> NW, NE, SW, SE;

    Stack.push(&root);

    while(!Stack.empty()){
        //cout << "In loop..";
        curr = Stack.top();

        qualifyBodies(curr, NW, NE, SW, SE);
        Stack.pop();

        if(!NW.empty()){
            curr->NW = new Node(curr->radius/2, curr->center - Vector(curr->radius/2, (-1)*curr->radius/2), NW);
            if(NW.size() > 1) Stack.push(curr->NW);
            NW.clear();
            memStack->push((void *)curr->NW);
            //cout << "NW Link: " << endl;
            //cout << "-- New node: --" << endl;
            //printNode(*curr->NW);
        }

        if(!NE.empty()){
            curr->NE = new Node(curr->radius/2, curr->center + Vector(curr->radius/2, curr->radius/2), NE);
            if(NE.size() > 1) Stack.push(curr->NE);
            NE.clear();
            memStack->push((void *)curr->NE);
            //cout << "NE Link: " << endl;
            //cout << "-- New node: --" << endl;
            //printNode(*curr->NE);

        }

        if(!SW.empty()){
            curr->SW = new Node(curr->radius/2, curr->center - Vector(curr->radius/2, curr->radius/2), SW);
            if(SW.size() > 1) Stack.push(curr->SW);
            SW.clear();
            memStack->push((void *)curr->SW);
            //cout << "SW Link: " << endl;
            //cout << "-- New node: --" << endl;
            //printNode(*curr->SW);
        }

        if(!SE.empty()){
            curr->SE = new Node(curr->radius/2, curr->center - Vector((-1)*curr->radius/2, curr->radius/2), SE);
            if(SE.size() > 1) Stack.push(curr->SE);
            SE.clear();
            memStack->push((void *)curr->SE);
            //cout << "SE Link: " << endl;
            //cout << "-- New node: --" << endl;
            //printNode(*curr->SE);
        }

        //printf("Links: %p, %p, %p, %p\n", curr->NW, curr->NE, curr->SW, curr->SE);
        /*printf("       Linked nodes: ");
        if(curr->NW) printNode(*curr->NW);
        if(curr->NE) printNode(*curr->NE);
        if(curr->SW) printNode(*curr->SW);
        if(curr->SE) printNode(*curr->SE);*/
        //printf("\n");
    }
    /*printf("Root links: ");
    if(root.NW) printNode(*root.NW);
    if(root.NE) printNode(*root.NE);
    if(root.SW) printNode(*root.SW);
    if(root.SE) printNode(*root.SE);*/
}

void qualifyBodies(Node *curr, list<Body> &NW, list<Body> &NE, list<Body> &SW, list<Body> &SE){
    Vector position;

    //cout << "Qualifying node: " << endl;
    //printNode(*curr);
    //cout << endl;

    for(const auto &body : curr->bodies){
        position = body.position - curr->center;

        if(position.x < 0 && position.y > 0) NW.emplace_back(body);
        else if(position.x >= 0 && position.y >= 0) NE.emplace_back(body);
        else if(position.x <= 0 && position.y <= 0) SW.emplace_back(body);
        else if(position.x > 0 && position.y < 0) SE.emplace_back(body);
    }
}