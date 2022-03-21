#include <stdbool.h>

#ifndef BARNES_HUT_HEADERS_H
#define BARNES_HUT_HEADERS_H

#endif //BARNES_HUT_HEADERS_H

// basic data structures:

extern double threshold;

typedef struct {
    double x;
    double y;
} vector;

typedef struct {
    double mass;
    vector position;
} body;

typedef struct {
    int size;
    int capacity;
    void **items;
} stack;


// quadtree:

struct node_struct{
    // TODO: parent->child->brothers representation for better memory efficiency
    int count;
    double size;
    vector centre;
    body pseudo_body;

    body *bodies; // pointer list

    struct node_struct* NW;
    struct node_struct* NE;
    struct node_struct* SW;
    struct node_struct* SE;

    struct node_struct *parent;
};

typedef struct node_struct node;

void construct_tree(node *root);
void traverse(node *root, void (*action)(node *chunk));

node *new_node(node *parent, stack* st, int count, double size, vector centre);
void qualify(node *curr, stack *NW, stack *NE, stack *SW, stack *SE);


// stack:

int default_opt(int x);
void construct_stack(stack *st, int cap);
void extend_stack(stack *st, int (*opt_fun)(int));
bool empty(stack *st);
void push(stack *st, void *new_item);
void *pop(stack *st);


//physics:
body compute_mass_centre(int count, body *bodies);
vector compute_force(body b1, body b2);
void compute_forces(double **forces, node *root, int count);
double distance(vector a, vector b);
void add(vector *to, vector from);
vector resultant_force(node *root, int i);


//system:
void construct_body_list(node *root, int count, double **state);
double **perform(double **state, int count, double accuracy, double radius);
double **vector_to_array(vector *list, int count);
void print_node(node *N);
void print_array(double **arr, int n);



void print_bodies(stack *st);
