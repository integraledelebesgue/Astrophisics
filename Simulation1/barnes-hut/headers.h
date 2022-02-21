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

struct node{
    int count;
    double size;
    point centre;

    body** bodies; // pointer list

    struct node* NW;
    struct node* NE;
    struct node* SW;
    struct node* SE;

    struct node *Parent;
};

typedef struct node Node;


// stack:

typedef struct {
    long size;
    long capacity;
    Node **items;
} Stack;

long default_opt(long x);
Stack *construct_stack(long cap);
void extend_stack(Stack *st, long (*opt_fun)(long));
bool empty(Stack *st);
void push(Stack *st, Node *new_item);
Node *pop(Stack *st);


//system:
body *construct_system(long length, double **state);
void construct_tree(long length, body *bodies, Node *root);