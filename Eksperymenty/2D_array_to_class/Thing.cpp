#include "Thing.h"
#include<utility>
#include<iostream>

using namespace std;


Thing::Thing(){
    x = 0;
    y = 0;
}

Thing::Thing(int *p){
    x = p[0];
    y = p[1];
}

void printAttr(const Thing &th){
    cout << th.x << ", " << th.y << endl;
}