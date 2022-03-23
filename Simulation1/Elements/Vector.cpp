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

Vector operator * (const Vector &vec, const double &scalar){
    return Vector(vec.x*scalar, vec.y*scalar);
}

Vector operator * (const double &scalar, const Vector &vec){
    return Vector(vec.x*scalar, vec.y*scalar);
}

/*
 * Vector3D operator*(const Scalar& scalar, const Vector3D& vect)
{
  return Vector(scalar*vect.x(), scalar*vect.y(), scalar*vect.z());
}

template <typename Scalar>
Vector3D operator*(const Vector3D& vect, const Scalar& scalar)
{
  return scalar*vect;
}
 */
