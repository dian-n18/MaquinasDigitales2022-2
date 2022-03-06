#include <iostream>
using namespace std;

int main(){
  int i;

  do {
      cout << "Ingresa un valor entre 0 y 10: ";
      cin >> i;
    }while(i >= 0 && i <= 10);

  cout << "El numero " << i << " no esta en el rango" << endl;

    return 0;
}