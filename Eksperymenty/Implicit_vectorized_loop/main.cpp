#include<iostream>
#include<utility>
#include<vector>
#include "Thing.h"

using namespace std;

// Observation: for (. : .) loop allows implicit conversion.

void arrange(const int n, vector<pair<int, int>> &vec){
    for(int i=0; i<n; i++)
        vec.push_back(pair<int, int> {i, 10*i});
}

void print(const int n, const vector<pair<int, int>> &vec){
    for(const Thing &th : vec)
        printAttr(th);
}

int main(void){
    vector<pair<int, int>> vec;
    arrange(5, vec);
    print(5, vec);

    return 0;
}