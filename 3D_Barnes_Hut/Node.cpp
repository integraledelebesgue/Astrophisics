#include "Node.h"
#include "Body.h"
#include<list>
#include<array>

using namespace std;


Node::Node(){
   center = array<double, 3> {0.0, 0.0, 0.0};
   radius = 0.0;
   mass_center = Body();
   bodies = list<Body> {};
   children = array<Node *, 8> {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
}

Node::Node(const array<double, 3> &center, const double &radius, const list<Body> &bodies){

}

void findMassCenter(Node &node){
    
}

array<Node *, 8> divideNode(const Node &){

}