#include "headers.h"
#include<stack>
#include<list>
#include<cstdio>

using namespace std;

void printNode(Node *node){
    printf("{");
    for(int i=0; i<node->count; i++){
        printf("[%lf, %lf, %lf], ", node->bodies[i].mass, node->bodies[i].position.x, node->bodies[i].position.y);
    }
    printf("}\n");
}

void traverse(Node &root){
    stack<Node *> Stack;
    Node *curr;

    Stack.push(&root);

    while(!Stack.empty()){
        curr = Stack.top();
        Stack.pop();
        if(curr){
            printNode(curr);
            if(curr->NW) Stack.push(curr->NW);
            if(curr->NE) Stack.push(curr->NE);
            if(curr->SW) Stack.push(curr->SW);
            if(curr->SE) Stack.push(curr->SE);
        }
    }
}

void constructTree(Node &root){
    Vector centre;
    Node *curr;

    stack<Node *> Stack;

    list<Body> NW;
    list<Body> NE;
    list<Body> SW;
    list<Body> SE;

    Stack.push(&root);

    while(!Stack.empty()){
        puts("  In loop!");
        curr = Stack.top();

        qualifyBodies(curr, NW, NE, SW, SE);

        if(!NW.empty()){
            centre.x = curr->centre.x - curr->size/4;
            centre.y = curr->centre.y + curr->size/4;

            curr->NW = new Node(NW.size(), curr->size/2, centre, NW.get_allocator().allocate(NW.size()));

            Stack.push(curr->NW);
        }

        if(!NE.empty()){
            centre.x = curr->centre.x + curr->size/4;
            centre.y = curr->centre.y + curr->size/4;

            curr->NW = new Node(NE.size(), curr->size/2, centre, NE.get_allocator().allocate(NE.size()));

            Stack.push(curr->NE);
        }

        if(!SW.empty()){
            centre.x = curr->centre.x - curr->size/4;
            centre.y = curr->centre.y - curr->size/4;

            curr->SW = new Node(SW.size(), curr->size/2, centre, SW.get_allocator().allocate(SW.size()));

            Stack.push(curr->SW);
        }

        if(!SE.empty()){
            centre.x = curr->centre.x + curr->size/4;
            centre.y = curr->centre.y - curr->size/4;

            curr->SE = new Node(SE.size(), curr->size/2, centre, SE.get_allocator().allocate(SE.size()));

            Stack.push(curr->SE);
        }

        Stack.pop();
    }
}

void qualifyBodies(Node *curr, list<Body> &NW, list<Body> &NE, list<Body> &SW, list<Body> &SE){
    puts("    Qualifying!");
    printNode(curr);
    for(int i=0; i<curr->count; i++){
        if(curr->centre.x - curr->bodies[i].position.x > 0 && curr->centre.y - curr->bodies[i].position.y < 0) NW.push_back(curr->bodies[i]);
        else if(curr->centre.x - curr->bodies[i].position.x < 0 && curr->centre.y - curr->bodies[i].position.y < 0) NE.push_back(curr->bodies[i]);
        else if(curr->centre.x - curr->bodies[i].position.x > 0 && curr->centre.y - curr->bodies[i].position.y > 0) SW.push_back(curr->bodies[i]);
        else if(curr->centre.x - curr->bodies[i].position.x < 0 && curr->centre.y - curr->bodies[i].position.y > 0) SE.push_back(curr->bodies[i]);
    }
}
