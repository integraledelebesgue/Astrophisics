#include <stdbool.h>

#ifndef BARNES_HUT_HEADERS_H
#define BARNES_HUT_HEADERS_H

#endif //BARNES_HUT_HEADERS_H

// basic data structures:

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    double mass;
    point position;
} body;


// quadtree:

struct node_struct{
    // TODO: parent->child->brothers representation for better memory efficiency
    long count;
    double size;
    point centre;
    body pseudo_body;

    body *bodies; // pointer list

    struct node_struct* NW;
    struct node_struct* NE;
    struct node_struct* SW;
    struct node_struct* SE;

    struct node_struct *Parent;
};

typedef struct node_struct node;

void construct_tree(node *root);

node *new_node(node *parent, body *bodies, long count, double size, point centre);
void qualify(node *Node, stack *NW, stack *NE, stack *SW, stack *SE);


// stack:

typedef struct {
    long size;
    long capacity;
    void **items;
} stack;

long default_opt(long x);
stack *construct_stack(long cap);
void extend_stack(stack *st, long (*opt_fun)(long));
bool empty(stack *st);
void push(stack *st, void *new_item);
void *pop(stack *st);


//physics:
body compute_mass_centre(int count, body *bodies);
point compute_force(body b1, body b2);
double distance(point a, point b);


//system:
body *construct_body_list(long count, double **state);
double **perform(long count, double **state)
