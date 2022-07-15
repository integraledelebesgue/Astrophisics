#include "Vector.h"
#include "Body.h"
#include "Node.h"
#include<stack>
#include<vector>
#include<array>

using namespace std;


void computeResultants(Node &root, vector<array<double, 3>> &results, double accuracy){
    for(Body &body : root.bodies)
        results.push_back((array<double, 3>)getResultantForce(root, body, accuracy));
}

Vector getResultantForce(const Node &root, Body &body, double threshold){
    stack<Node *> Stack;
    Node *curr;
    double distance;
    Vector result;

    for(Node *node : root.children)
        if(node)
            Stack.push(node);

    while(!Stack.empty()){
        curr = Stack.top();
        Stack.pop();

        if((bool)(distance = norm(body.getPosition() - curr->mass_center.getPosition()))){
            if(curr->isLeaf() || curr->radius / distance < threshold)
                result += graviForce(body, curr->mass_center);

            else
                for(Node *node : curr->children)
                    if(node)
                        Stack.push(node);
        }
    }

    return result;
}