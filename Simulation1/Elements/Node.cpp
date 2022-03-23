#include "Node.h"
#include<iostream>
#include<list>
#include<stack>

Node::Node(){
    count = 0;
    radius = 0;
    center = Vector();
    bodies = std::list<Body>();
    pseudobody = Body();
    NW = nullptr;
    NE = nullptr;
    SW = nullptr;
    SE = nullptr;
}

Node::Node(const Node &other){
    count = other.count;
    radius = other.radius;
    center = other.center;
    bodies = other.bodies;
    pseudobody = other.pseudobody;
    NW = other.NW;
    NE = other.NE;
    SW = other.SW;
    SE = other.SE;
}

Node::Node(const int &Count, const double &Radius, const Vector &Center, const std::list<Body> &Bodies, const Body &Pseudobody){
    count = Count;
    radius = Radius;
    center = Center;
    bodies = Bodies;
    pseudobody = Pseudobody;
}

Node::Node(const double &Radius, const Vector &Center, const std::list<Body> &Bodies){
    count = Bodies.size();
    center = Center;
    radius = Radius;
    bodies = Bodies;
    pseudobody = findMassCenter(*this);

    NW = nullptr;
    NE = nullptr;
    SW = nullptr;
    SE = nullptr;
}

Body Node::findMassCenter(const Node &node){
    double total_mass = 0;
    Vector centre;

    for(const auto & body : node.bodies){
        total_mass += body.mass;
        centre += (body.position * body.mass);
    }

    centre.x /= total_mass;
    centre.y /= total_mass;

    return Body(total_mass, centre);
}

void Node::traverse(void (*foo)(const Node &node)) const{
    std::stack<Node> Stack;
    Node *curr;

    Stack.push(*this);

    while(!Stack.empty()){
        curr = &Stack.top();
        foo(*curr);
        Stack.pop();
        if(curr->NW) Stack.push(*curr->NW);
        if(curr->NE) Stack.push(*curr->NE);
        if(curr->SW) Stack.push(*curr->SW);
        if(curr->SE) Stack.push(*curr->SE);
    }
}

void printNode(const Node &node){
    printf("Node {\n");

    if(!node.NW && !node.NE && !node.SW && !node.SE) printf("* Leaf node *\n");
    printf("Count: %d, Center: (%lf, %lf), Radius: %lf\n", node.count, node.center.x, node.center.y, node.radius);
    printf("Pseudobody: mass: %lf, position: (%lf, %lf)\n", node.pseudobody.mass, node.pseudobody.position.x, node.pseudobody.position.y);
    printf("Bodies: \n");

    for(const auto &body : node.bodies)
        printf("mass: %lf, position: (%lf, %lf)\n", body.mass, body.position.x, body.position.y);

    printf("}\n");
}
