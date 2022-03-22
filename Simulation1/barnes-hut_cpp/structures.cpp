/*#include "headers.h"

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

    Vector operator + (Vector const &vec){
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

    Body(double m, const Vector &p){
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
};*/