#include <math.h>
#include <malloc.h>
#include<stdbool.h>
#include "headers.h"


// real type 2-dim raw state array to body type list:
body *construct_system(long length, double **state){
    body *bodies = (body *)malloc(length*sizeof(body));

    for(long i=0; i<length; i++){
        bodies[i].mass = state[i][0];
        bodies[i].position.x = state[i][1];
        bodies[i].position.y = state[i][2];
    }

    return bodies;
}