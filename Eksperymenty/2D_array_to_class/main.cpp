#include "Thing.h"
#include<cstdlib>

using namespace std;


void printThings(int **tab, int n){
    for(int i=0; i<n; i++)
        printAttr(tab[i]);
}

int main(void){
    int **tab = (int **)malloc(10 * sizeof(int *));
    
    for(int i=0; i<10; i++){ 
        tab[i] = (int *)malloc(2 * sizeof(int));
        tab[i][0] = i;
        tab[i][1] = 10*i;
    }

    printThings(tab, 10);

    return 0;
}