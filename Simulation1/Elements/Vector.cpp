#include "Vector.h"

Vector::Vector(){
    x = 0.0;
    y = 0.0;
}

Vector::Vector(double x_coord, double y_coord){
    x = x_coord;
    y = y_coord;
}

Vector::Vector(const Vector &other){
    x = other.x;
    y = other.y;
}

void Vector::operator += (const Vector &other){
    x += other.x;
    y += other.y;
}

void Vector::operator *= (const double &scalar){
    x *= scalar;
    y *= scalar;
}


Vector operator * (const Vector &vec, const double &scalar){
    return {vec.x*scalar, vec.y*scalar};
}

Vector operator * (const double &scalar, const Vector &vec){
    return {vec.x*scalar, vec.y*scalar};
}

Vector operator / (const Vector &vec, const double &scalar){
    return {vec.x/scalar, vec.y/scalar};
}

Vector operator / (const double &scalar, const Vector &vec){
    return {vec.x/scalar, vec.y/scalar};
}

Vector operator - (const Vector &vec1, const Vector &vec2){
    return {vec1.x - vec2.x, vec1.y - vec2.y};
}

Vector operator + (const Vector &vec1, const Vector &vec2){
    return {vec2.x + vec1.x, vec2.y + vec1.y};
}

void vectorToArr(double **arr, Vector *vectors, int count){
    for(int i=0; i<count; i++){
        arr[i][0] = vectors[i].x;
        arr[i][1] = vectors[i].y;
    }
}