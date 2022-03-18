#include <stdbool.h>

#ifndef BARNES_HUT_HEADERS_H
#define BARNES_HUT_HEADERS_H

#endif //BARNES_HUT_HEADERS_H

// basic data structures:

typedef struct {
    double x;
    double y;
} vector;

typedef struct {
    double mass;
    vector position;
} body;

typedef struct {
    long size;
    long capacity;
    void **items;
} stack;


// quadtree:

struct node_struct{
    // TODO: parent->child->brothers representation for better memory efficiency
    long count;
    double size;
    vector centre;
    body pseudo_body;

    body *bodies; // pointer list

    struct node_struct* NW;
    struct node_struct* NE;
    struct node_struct* SW;
    struct node_struct* SE;

    struct node_struct *parent;
    long rank;
};

typedef struct node_struct node;

void construct_tree(node *root);

node *new_node(node *parent, body *bodies, long count, double size, vector centre);
void qualify(node *Node, stack *NW, stack *NE, stack *SW, stack *SE);


// stack:

long default_opt(long x);
stack *construct_stack(long cap);
void extend_stack(stack *st, long (*opt_fun)(long));
bool empty(stack *st);
void push(stack *st, void *new_item);
void *pop(stack *st);


//physics:
body compute_mass_centre(int count, body *bodies);
vector compute_force(body b1, body b2);
double **compute_forces(node *root, long count);
double distance(vector a, vector b);
vector resultant_force(node *root, long i);


//system:
body *construct_body_list(long count, double **state);
double **perform(long count, double **state);
double **point_to_array(vector *list, long length);
