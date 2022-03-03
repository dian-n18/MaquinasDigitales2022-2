#include <iostream>
using namespace std;

int main(){
    float v;
    cout << "Ingresa un valor: ";
    cin >> v;

    if(v > 0){
        cout << "El numero es mayor a cero" << endl;
    }
    else{
        v = v + 10;
        cout << "El nuevo valor es: " << v << endl;
    }

    return 0;
}