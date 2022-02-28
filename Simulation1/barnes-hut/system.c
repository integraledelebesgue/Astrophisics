#include <math.h>
#include <malloc.h>
#include<stdbool.h>
#include "headers.h"

body *construct_body_list(long count, double **state){
    /// Builds body-type objects list from 2-dim array of bodies' states taken from Python.
    body *bodies = (body *)malloc(count*sizeof(body));

    for(long i=0; i<length; i++){
        bodies[i].mass = state[i][0];
        bodies[i].position.x = state[i][1];
        bodies[i].position.y = state[i][2];
    }

    return bodies;
}

double **perform(long count, double **state){
    /// Main function to compute forces from a state array given.
    *forces = (double *)malloc(count*sizeof(double));

    node *root = (node *)malloc(sizeof(node));
    root->count = count;
    root->centre = point zero(0, 0);
    root->bodies = construct_body_list(count, state);
    root->pseudo_body = compute_mass_centre(count, root->bodies);

    construct_tree(root);

    compute_forces(root->bodies, forces); //TODO - global force computation

    return forces;
}