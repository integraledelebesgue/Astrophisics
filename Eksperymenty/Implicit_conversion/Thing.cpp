#include<utility>
#include<iostream>
#include "Thing.h"

using namespace std;

Thing::Thing(void){
    x = 0;
    y = 0;
}

//Thing::Thing(const pair<int, int> &p){
//    x = p.first;
//    y = p.second;
//}

void getAttr(const Thing &th){
    cout << th.x << ", ";
    cout << th.y;
    cout << "\n";
}
