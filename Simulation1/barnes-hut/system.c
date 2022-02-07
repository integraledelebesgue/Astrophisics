#include <math.h>
#include<stdbool.h>

struct system {
    int *bodies;
    int mass_scale;
    int radius_scale;
};

struct point {
    double x;
    double y;
};

struct velocity {
    double x_direction;
    double y_direction;
};

struct body {
    double mass;  // mantises only
    double radius;
    struct point position;
    struct velocity velocity;
};

struct node {
    int data;
    double size;
    struct point centre;
    bool divided;

    struct body* bodies;

    struct node* NW;
    struct node* NE;
    struct node* SW;
    struct node* SE;
};
