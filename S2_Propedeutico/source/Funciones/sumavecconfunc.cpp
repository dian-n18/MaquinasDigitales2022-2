#include <iostream>
using namespace std;

void printVect(int *v, int size);
void sumVect(int *va, int *vb, int *vs, int size);

int main(){

  int v1[3] = {1,2,3}, v2[3] = {3,1,2}, v3[3] = {2,3,1};
  int vr[3];

  printVect(v1, 3);
  printVect(v2, 3);
  printVect(v3, 3);

    return 0;
}

void printVect(int *v, int size){
    cout << "V = {";
    for(int i=0; i<size; i++){
        cout << " " << v[i] << " ";
    }
    cout << "}\n" << endl;
}

void sumVect(int *va, int *vb, int *vs, int size){
    vs[i] = va[i] + vb[i]
}