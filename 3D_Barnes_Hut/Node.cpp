#include "Node.h"
#include "Body.h"
#include<list>
#include<array>
#include<vector>

using namespace std;


Node::Node(){
   center = Vector();
   radius = 0.0;
   mass_center = Body();
   bodies = list<Body> {};
   children = array<Node *, 8> {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
}

Node::Node(const Vector &_center, const double &_radius, const list<Body> &_bodies){
   center = _center;
   radius = _radius;
   bodies = _bodies;
   mass_center = massCenter(_bodies);
   children = array<Node *, 8> {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
}

bool Node::trivial(){
   return bodies.size() > 1;
}

bool Node::isLeaf(){
   for(const Node *node : children)
      if(node)
         return false;

   return true;
}

void divideNode(Node &node, vector<Node *> processed){
   array<list<Body>, 8> lists;

   for(const Body &body : node.bodies)
      lists[qualify(body, node.center)].push_back(body);

   for(int i=0; i<8; i++)
      if(!lists[i].empty()){
         node.children[i] = new Node{Vector(), node.radius / 2.0, lists[i]};  // TODO: new center.
         processed.push_back(node.children[i]);
      }
}