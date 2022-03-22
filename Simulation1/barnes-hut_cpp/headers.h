#ifndef BARNES_HUT_CPP_HEADERS_H
#define BARNES_HUT_CPP_HEADERS_H

#include<list>

// Data:

class Vector{
public:
    double x;
    double y;

    Vector(){
        x = 0.0;
        y = 0.0;
    }

    Vector(double x_c, double y_c){
        x = x_c;
        y = y_c;
    }

    Vector(const Vector &other){
        x = other.x;
        y = other.y;
    }

    Vector operator += (Vector const &vec){
        Vector res;
        res.x = x + vec.x;
        res.y = y + vec.y;
        return res;
    }
};

class Body{
public:
    double mass;
    Vector position;

    Body(){
        mass =0.0;
    }

    Body(double m, Vector &p){
        mass = m;
        position = p;
    }
};

class Node{
public:
    int count;
    double size;
    Vector centre;

    Body *bodies;

    Body pseudobody;

    Node *NW;
    Node *NE;
    Node *SW;
    Node *SE;


    Node(int n, double s, const Vector &C, Body B[]){
        count = n;
        size = s;
        centre = C;
        bodies = B;

        pseudobody = findMassCentre();

        NW = nullptr;
        NE = nullptr;
        SW = nullptr;
        SE = nullptr;
    }

    Node(Node &other){
        count = other.count;
        size = other.size;
        centre = other.centre;
        bodies = other.bodies;
        pseudobody = other.pseudobody;
        NW = other.NW;
        NE = other.NE;
        SW = other.SW;
        SE = other.SE;
    }

    Body findMassCentre(){
        double total_mass = 0;
        Vector m_centre;

        for(int i=0; i<count; i++){
            total_mass += bodies[i].mass;
            m_centre.x += bodies[i].mass*bodies[i].position.x;
            m_centre.y += bodies[i].mass*bodies[i].position.y;
        }

        m_centre.x /= total_mass;
        m_centre.y /= total_mass;

        return Body(total_mass, m_centre);
    }

    ~Node(){
        delete bodies;
    }
};

// Quadtree:
void constructTree(Node &root);
void qualifyBodies(Node *curr, std::list<Body> &NW, std::list<Body> &NE, std::list<Body> &SW, std::list<Body> &SE);
void printNode(Node *node);
void traverse(Node &root);


// System:
void arrayToBody(double **arr, Body *bodies, int count);
double **perform(double **state, int count, double radius, double accuracy);
void vectorToArray(Vector *vec, double **arr, int count);


// Physics:
Vector computeForce(const Body &particle, const Body &source);
double distance(const Vector &a, const Vector &b);
void computeForces(Vector *forces, Node &root);
Vector resultantForce(Node &root, int i);



#endif //BARNES_HUT_CPP_HEADERS_H

