#include <math.h>
#include <malloc.h>
#include<stdbool.h>
#include "headers.h"

body *construct_body_list(long count, double **state){
    /// Builds body-type objects list from 2-dim array of bodies' states taken from Python.
    body *bodies = (body *)malloc(count*sizeof(body));

    for(long i=0; i<count; i++){
        bodies[i].mass = state[i][0];
        bodies[i].position.x = state[i][1];
        bodies[i].position.y = state[i][2];
    }

    return bodies;
}

// TODO - theta parameter

double **perform(long count, double **state){
    /// Main function to compute forces from a state array given.

    node *root = (node *)malloc(sizeof(node));
    root->count = count;
    root->centre = vector zero {.x = 0, .y = 0};
    root->bodies = construct_body_list(count, state);
    root->pseudo_body = compute_mass_centre(count, root->bodies);

    construct_tree(root);

    double **forces = compute_forces(root, count); //TODO - global force computation

    return forces;
}

double **point_to_array(vector *list, long length){
    double **arr = (double **)malloc(length*sizeof(double));

    for(long i = 0; i < length; i++){
        arr[i] = (double *)malloc(2*sizeof(double));
        arr[i][0] = list[i].x;
        arr[i][1] = list[i].y;
    }

    return arr;
}