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
    int count;
    double size;
    point centre;

    body** bodies; // pointer list

    struct node_struct* NW;
    struct node_struct* NE;
    struct node_struct* SW;
    struct node_struct* SE;

    struct node_struct *Parent;
};

typedef struct node_struct node;


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


//system:
body *construct_system(long length, double **state);
void construct_tree(long length, body *bodies, node *root);