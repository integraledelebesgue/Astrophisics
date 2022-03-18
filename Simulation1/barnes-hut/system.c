#include <malloc.h>
#include "headers.h"

body *construct_body_list(int count, double **state){
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

// TODO - Multithreading

double **perform(int count, double **state, double accuracy){
    /// Main function to compute forces from a state array given.
    threshold = accuracy;
    vector zero = {.x = 0, .y = 0};

    node *root = (node *)malloc(sizeof(node));
    root->count = count;
    root->centre = zero;
    root->bodies = construct_body_list(count, state);
    root->pseudo_body = compute_mass_centre(count, root->bodies);

    construct_tree(root);

    double **forces = compute_forces(root, count); //TODO - global force computation

    return forces;
}

double **vector_to_array(vector *list, int count){
    double **arr = (double **)malloc(count * sizeof(double));

    for(long i = 0; i < count; i++){
        arr[i] = (double *)malloc(2*sizeof(double));
        arr[i][0] = list[i].x;
        arr[i][1] = list[i].y;
    }

    return arr;
}