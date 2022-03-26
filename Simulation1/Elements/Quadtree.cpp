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

        if(curr->radius == 0){
            printf("!!! Radius 0 !!!");
            exit(0);
        }

        qualifyBodies(curr, NW, NE, SW, SE);
        Stack.pop();

        if(!NW.empty()){
            curr->NW = new Node(curr->radius/2, curr->center - Vector(curr->radius/2, (-1)*curr->radius/2), NW);
            if(NW.size() > 1) Stack.push(curr->NW);
            NW.clear();
            cout << "-- New node: --" << endl;
            printNode(*curr->NW);
        }

        if(!NE.empty()){
            curr->NE = new Node(curr->radius/2, curr->center + Vector(curr->radius/2, curr->radius/2), NE);
            if(NE.size() > 1) Stack.push(curr->NE);
            NE.clear();
            cout << "-- New node: --" << endl;
            printNode(*curr->NE);

        }

        if(!SW.empty()){
            curr->SW = new Node(curr->radius/2, curr->center - Vector(curr->radius/2, curr->radius/2), SW);
            if(SW.size() > 1) Stack.push(curr->SW);
            SW.clear();
            cout << "-- New node: --" << endl;
            printNode(*curr->SW);
        }

        if(!SE.empty()){
            curr->SE = new Node(curr->radius/2, curr->center - Vector((-1)*curr->radius/2, curr->radius/2), SE);
            if(SE.size() > 1) Stack.push(curr->SE);
            SE.clear();
            cout << "-- New node: --" << endl;
            printNode(*curr->SE);
        }
    }
}

void qualifyBodies(Node *curr, list<Body> &NW, list<Body> &NE, list<Body> &SW, list<Body> &SE){
    Vector position;

    cout << "Qualifying node: " << endl;
    printNode(*curr);
    cout << endl;

    for(const auto &body : curr->bodies){
        position = body.position - curr->center;

        if(position.x > 0 && position.y < 0) NW.emplace_back(body);
        else if(position.x <= 0 && position.y <= 0) NE.emplace_back(body);
        else if(position.x >= 0 && position.y >= 0) SW.emplace_back(body);
        else if(position.x < 0 && position.y > 0) SE.emplace_back(body);

    }

    cout << " $$ Qualified nodes: $$" << endl;
    printf("NW: {");
    for(auto const &body : NW) printf("[%lf, %lf, %lf], ", body.mass, body.position.x, body.position.y);
    printf("}\n\n");

    printf("NE: {");
    for(auto const &body : NE) printf("[%lf, %lf, %lf], ", body.mass, body.position.x, body.position.y);
    printf("}\n\n");

    printf("SW: {");
    for(auto const &body : SW) printf("[%lf, %lf, %lf], ", body.mass, body.position.x, body.position.y);
    printf("}\n\n");

    printf("SE: {");
    for(auto const &body : SE) printf("[%lf, %lf, %lf], ", body.mass, body.position.x, body.position.y);
    printf("}\n\n");
}