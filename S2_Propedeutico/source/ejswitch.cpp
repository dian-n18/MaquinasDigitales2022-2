#include <iostream>
using namespace std;

int main(){

 float v1, v2;
 int opt;

 cout << "Ingresa numero 1 a operar: "; cin >> v1;
 cout << "Ingresa numero 2 a operar: "; cin >> v2;
 cout << "Ingresa la operación a realizar [1,+],[2,-],[3,*],[4,/]: "; cin >> opt;

  switch(opt){
    case 1:
      cout << v1 << "+" << v2 << "=" << v1+v2 << endl;
      break;

      case 2:
      cout << v1 << "-" << v2 << "=" << v1-v2 << endl;
      break;

      case 3:
      cout << v1 << "*" << v2 << "=" << v1*v2 << endl;
      break;

      case 4:
      cout << v1 << "/" << v2 << "=" << v1/v2 << endl;
      break;
  }
     
      
    
    return 0;
}
