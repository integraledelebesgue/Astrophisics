#include<iostream>
#include<utility>
#include<vector>
#include<cstdlib>
#include "Thing.h"

using namespace std;

// Observation: static_cast allows to convert a C-style array data to an abstractive C++ class type immedietely.
// Doesn't require conversion constructor.

void fill(pair<int, int> *const tab, int n){
    for(int i=0; i<n; i++){
    tab[i].first = i;
    tab[i].second = 10*i;
    }
}

void print(Thing *tab, int n){
    for(int i=0; i<n; i++) getAttr(tab[i]);
}

int main(void){
    pair<int, int> *tab = static_cast<pair<int, int> *>(malloc(5*sizeof(pair<int, int>)));
    fill(tab, 5);
    print((Thing *)tab, 5);

    return 0;
}