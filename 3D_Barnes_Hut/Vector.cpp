#include "Vector.h"
#include<cmath>

using namespace std;


Vector::Vector(){
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector::Vector(const Vector &other){
    x = other.x;
    y = other.y;
    z = other.z;
}

Vector::Vector(const double x_coord, const double y_coord, const double z_coord){
    x = x_coord;
    y = y_coord;
    z = z_coord;
}

Vector::Vector(const array<double, 3> &arr){
    x = arr[0];
    y = arr[1];
    z = arr[2];
}

void Vector::operator +=(const Vector &other){
    x += other.x;
    y += other.y;
    z += other.z;
}

void Vector::operator *=(const double &scalar){
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

void Vector::operator /=(const double &scalar){
    x /= scalar;
    y /= scalar;
    z /= scalar;
}

Vector::operator std::array<double, 3>(){
    return array<double, 3> {x, y, z};
}

Vector operator -(const Vector &from, const Vector &what){
    return Vector{from.x - what.x, from.y - what.y, from.z - what.z};
}

Vector operator *(const double &scalar, const Vector &vec){
    return Vector{vec.x * scalar, vec.y * scalar, vec.z * scalar};
}

Vector operator /(const Vector &vec, const double &scalar){
    return Vector{vec.x / scalar, vec.y / scalar, vec.z / scalar};
}

bool operator ==(const Vector &v1, const Vector &v2){
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

Vector sum(const list<Vector> &vectors){
    Vector result;
    for(const Vector &vec : vectors) result += vec;
    return result;
}

double norm(const Vector &vec){
    return sqrt(
        pow(vec.x, 2) + \
        pow(vec.y, 2) + \
        pow(vec.z, 2)
    );
}

short int segmentHash(const Vector &vec){
    return \
    (int)( vec.x > 0 ) * 2 + \
    (int)( vec.y > 0 ) * 3 + \ 
    (int)( vec.z > 0 ) * 7;
}


