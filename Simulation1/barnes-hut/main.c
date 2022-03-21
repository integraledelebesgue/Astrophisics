#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"
#include<math.h>


int main(void){
    int count = 10;
    int i;

    srand(time(NULL));

    puts("Allocation..");

    double **state;
    vector curr;
    state = (double **)malloc(count*sizeof(double));

    puts("Allocated!");

    for(i=0; i<count; i++){
        puts("In loop..");
        state[i] = (double *)malloc(3*sizeof(double));
        state[i][0] = (double)abs(rand()%100);

        state[i][1] = (pow(-1, (double)(rand()%100))*(double)(rand()%100));
        state[i][2] = (pow(-1, (double)(rand()%100))*(double)(rand()%100));
    }

    print_array(state, count);

    double **forces;

    forces = perform(state, count, 0.2, 100.0);


    return 0;
}

