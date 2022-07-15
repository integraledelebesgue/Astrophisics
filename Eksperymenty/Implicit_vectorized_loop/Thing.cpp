#include<utility>
#include<iostream>
#include<string>
#include "Thing.h"

Thing::Thing(){
    x = 0;
    y = 0;
}

Thing::Thing(const pair<int, int> &p){
    x = p.first;
    y = p.second;
}

void printAttr(const Thing &th){
    cout << th.x << ", " << th.y << endl;
}