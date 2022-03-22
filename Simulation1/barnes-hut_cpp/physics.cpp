#include "headers.h"
#include<stack>
#include<cmath>

double threshold;

using namespace std;

Vector computeForce(const Body &particle, const Body &source){
    /// Returns a force vector representing gravity affected on "particle" by "source.
    double d = distance(particle.position, source.position);

    double scalar_force = pow(10, -11)*6.67*particle.mass*source.mass/(d*d);



    return {scalar_force*(source.position.x - particle.position.x)/d, scalar_force*(source.position.y - particle.position.y)/d};
}

double distance(const Vector &a, const Vector &b){
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void computeForces(Vector *forces, Node &root){
    for(int i=0; i<root.count; i++){
        forces[i] = resultantForce(root, i);
    }
}

Vector resultantForce(Node &root, int i){
    stack<Node *> Stack;
    Node *curr;
    Vector result;
    double scale;
    double dist;

    Stack.push(&root);

    while(!Stack.empty()){
        curr = Stack.top();
        Stack.pop();

        if((bool)(dist = distance(curr->pseudobody.position, curr->bodies[i].position))){
            scale = curr->size/dist;
            if(scale <= threshold) result += computeForce(root.bodies[i], curr->pseudobody);
            else{
                if(curr->SW) Stack.push(curr->NW);
                if(curr->SW) Stack.push(curr->NE);
                if(curr->SW) Stack.push(curr->SW);
                if(curr->SW) Stack.push(curr->SE);
            }
        }
    }
    return result;
}