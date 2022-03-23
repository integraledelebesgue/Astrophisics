#include "Node.h"

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