#ifndef VECTOR_H
#define VECTOR_H

#include<array>
#include<list>;

using namespace std;


class Vector{
private:
    double x, y, z;

public:
    Vector();
    Vector(const Vector &);
    Vector(double , double , double);
    Vector(const array<double, 3> &);

    void operator +=(const Vector &);
    void operator *=(const double &scalar);
    void operator /=(const double &scalar);

    operator array<double, 3>();

    friend double norm(const Vector &vec);
    friend short int segmentHash(const Vector &vec);
    friend Vector operator -(const Vector &, const Vector &);
    friend Vector operator *(const double &, const Vector &);
    friend Vector operator /(const Vector &vec, const double &scalar);
    friend bool operator ==(const Vector &, const Vector &);
    friend Vector sum(const list<Vector> &);
};


double norm(const Vector &vec);
short int segmentHash(const Vector &vec);
Vector operator -(const Vector &, const Vector &);
Vector operator *(const double &, const Vector &);
Vector operator /(const Vector &vec, const double &scalar);
bool operator ==(const Vector &, const Vector &);
Vector sum(const list<Vector> &);


#endif 