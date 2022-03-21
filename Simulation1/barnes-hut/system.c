#include <malloc.h>
#include "headers.h"

#define debug 1

double threshold;

void construct_body_list(node *root, int count, double **state){
    /// Builds body-type objects list from 2-dim array of bodies' states taken from Python.
    //body *bodies = (body *)malloc(count*sizeof(body));

    for(int i=0; i<count; i++){
        root->bodies[i].mass = state[i][0];
        root->bodies[i].position.x = state[i][1];
        root->bodies[i].position.y = state[i][2];
    }
}

// TODO - Multithreading

double **perform(double **state, int count, double accuracy, double radius){
    /// Main function to compute forces from a state array given.
    threshold = accuracy;
    vector zero = {.x = 0, .y = 0};

    puts("Main function running..");

    node *root = (node *)malloc(sizeof(node));
    root->count = count;
    root->centre = zero;
    root->size = radius;
    //root->bodies = construct_body_list(count, state);

    root->bodies = (body *)malloc(count * sizeof(body *));



    puts("Constructing body list..");

    construct_body_list(root, count, state);

    root->pseudo_body = compute_mass_centre(count, root->bodies);

    puts("Constructing tree..");

    construct_tree(root);


    puts("Quadtree:");
    traverse(root, print_node);


    puts("Computing forces..");

    //double **forces = compute_forces(root, count);
    //vector *forces = (vector *)malloc(count * sizeof(vector *));

    puts("Allocating forces array..");

    double **forces = (double **)malloc(count*sizeof(double));
    for(int i=0; i<count; i++){
        forces[i] = (double *)malloc(2*sizeof(double));
    }

    puts("Forces array ready! Computing forces..");

    compute_forces(forces, root, count);


    puts("Computation finished!");
    print_array(forces, count);


    //traverse(root, free);  // requires test, possibly not time-efficient.

    return forces;
}

double **vector_to_array(vector *list, int count){
    /// Transforms a list of vectors to a 2-dim real array.
    double **arr = (double **)malloc(count * sizeof(double));

    for(int i = 0; i < count; i++){
        arr[i] = (double *)malloc(2*sizeof(double));
        arr[i][0] = list[i].x;
        arr[i][1] = list[i].y;
    }

    return arr;
}

void print_node(node *N){
    printf("Quadtree node: count: %d, size: %lf, centre: (%lf, %lf), centre of mass: (%lf, %lf, %lf), bodies: \n",
           N->count, N->size, N->centre.x, N->centre.y, N->pseudo_body.mass, N->pseudo_body.position.x,
           N->pseudo_body.position.y);

    printf("{");
    for(int i=0; i<N->count; i++){
        printf("[%lf, %lf, %lf], \n", N->bodies[i].mass, N->bodies[i].position.x, N->bodies[i].position.y);

    }
    printf("}\n");
}

void print_array(double **arr, int n){
    for(int i=0; i<n; i++){
        printf("[%lf, %lf, %lf]\n", arr[i][0], arr[i][1], arr[i][2]);
    }
}