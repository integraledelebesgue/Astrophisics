#ifndef BARNES_HUT_HEADERS_H
#define BARNES_HUT_HEADERS_H

#endif //BARNES_HUT_HEADERS_H

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    double mass;
    point position;
} body;

struct node{
    int count;
    double size;
    point centre;

    body* bodies;

    struct node* NW;
    struct node* NE;
    struct node* SW;
    struct node* SE;

    struct node *Parent;
};

typedef struct node Node;

typedef struct {
    long top;
    body **bodies;
} Stack;
