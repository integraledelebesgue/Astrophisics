#include <iostream>
#include "headers.h"
#include<random>

using namespace std;

void print_arr(double **arr, int count);

void print_arr(double **arr, int count){
    for(int i=0; i<count; i++){
        printf("[%lf, %lf, %lf]\n", arr[i][0], arr[i][1], arr[i][2]);
    }
    printf("\n");
}

int main() {

    srandom(time(nullptr));

    int count = 5;
    int i;
    double **state = new double*;

    for(i=0; i<count; i++){
        state[i] = new double[3];
        state[i][0] = random()%100;
        state[i][1] =  pow(-1, random())*(random()%100);
        state[i][2] = pow(-1, random())*(random()%100);
    }

    print_arr(state, count);

    double **forces = new double *;

    for(i=0; i<count; i++){
        forces[i] = new double[2];
    }

    forces = perform(state, count, 100.0, 0.2);

    print_arr(forces, count);

    return 0;
}
