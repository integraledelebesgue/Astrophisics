#include <iostream>
#include "Body.h"
#include "Vector.h"
#include "Node.h"
#include<list>
#include<cmath>


using namespace std;

void printArr(double **arr, int count){
    printf("{\n");
    for(int i=0; i<count; i++){
        printf("[%lf, %lf, %lf]\n", arr[i][0], arr[i][1], arr[i][2]);
    }
    printf("}\n");
}


int main(){
    int i, count = 10;
    double *state[count];

    srandom(time(nullptr));

    for(i=0; i<count; i++){
        state[i] = new double[3];
        state[i][0] = 10.0 + (double)(random()%50);
        state[i][1] = pow(-1, random()+1)*(double)(random()%100);
        state[i][2] = pow(-1, random())*(double)(random()%100);
    }

    cout << "Initialize:" << endl;

    printArr(state, count);

    list<Body> bodies;

    cout << "Conversion:" << endl;

    stateToBody(state, bodies, count);

    for(const auto &body : bodies){
        printf("mass: %lf, position: (%lf, %lf)\n", body.mass, body.position.x, body.position.y);
    }

    for(i=0; i<count; i++) delete(state[i]);

    cout << endl << "Root node:" << endl;

    Node root(100.0, Vector(), bodies);

    root.traverse(printNode);

    return 0;
}
