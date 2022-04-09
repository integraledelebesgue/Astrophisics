#include "Vector.h"
#include "Body.h"
#include "Node.h"
#include "Physics.h"
#include "memory.h"
#include<cmath>
#include<stack>
#include <cstdio>

//double threshold;

Vector computeForce(const Body &particle, const Body &source){
    return direction(particle.position, source.position) * particle.mass * source.mass;
}

double distance(const Vector &v1, const Vector &v2){
    return sqrt(pow(v1.x - v2.x, 2)+pow(v1.y - v2.y, 2));
}

Vector direction(const Vector &a, const Vector &b){
    return (b-a)/pow(distance(a, b), 3);
}

void computeForces(const Node &root, Vector *result){
    int i = 0;
    for(const auto &body : root.bodies)
        result[i++] = computeResultantForce(root, body);
}

Vector computeResultantForce(const Node &root, const Body &body){
    Vector result(0, 0);
    double dist;
    Node *curr;
    std::stack<Node *> Stack;

    //printf("In resultant.. ");

    if(root.NW) Stack.push(root.NW);
    if(root.NE) Stack.push(root.NE);
    if(root.SW) Stack.push(root.SW);
    if(root.SE) Stack.push(root.SE);

    while(!Stack.empty()){
        //printf("In loop!\n");
        curr = Stack.top();
        Stack.pop();

        if((bool)(dist = distance(body.position, curr->pseudobody.position))){
            if (!(curr->NW) && !(curr->NE) && !(curr->SW) && !(curr->SE)){
                result += computeForce(body, curr->pseudobody);
            }

            else if((curr->radius/dist < threshold)){
                //printf(" ..pseudobody.. ");
                result += computeForce(body, curr->pseudobody);
            }

            else{
                //printf("    Lower level! ");
                if(curr->NW) Stack.push(curr->NW);
                if(curr->NE) Stack.push(curr->NE);
                if(curr->SW) Stack.push(curr->SW);
                if(curr->SE) Stack.push(curr->SE);

                /*if(!curr->NW && !curr->NE && !curr->SW && !curr->SE)
                    result += computeForce(body, curr->pseudobody);*/
            }
        }
    }

    //printf("\nResult: [%lf, %lf]\n", result.x, result.y);
    return result;
}
