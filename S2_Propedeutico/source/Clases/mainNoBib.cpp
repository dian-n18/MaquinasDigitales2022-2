#include <iostream>
using namespace std;

class TarjetaBancaria{
   public:
   string numTarjeta;
   string nombreTarjeta;
   string BancoEmisor;
   int mesVig;
   int anioVig;
   int nipTarjeta;

   TarjetaBancaria(string num_Tarjeta, string nombreTarjeta, string BancoEmisor,
                   int mesVig, int anioVig, int nipTarjeta){

        numTarjeta = num_Tarjeta;
        this->nombreTarjeta = nombreTarjeta;
        this->BancoEmisor = BancoEmisor;
        this->mesVig = mesVig;
        this->anioVig = anioVig;
        this->nipTarjeta = nipTarjeta;
   }


   void ActivarTarjeta(){
       cout << "Tarjeta de " << nombreTarjeta << " activada." << endl;
   }

   void AnularTarjeta(){
       cout << "Tarjeta con terminación: " << numTarjeta.substr(12,4) << " anulada." << endl;
   }

   void Pagar(float cantidad, int nip){
       if(nip == nipTarjeta){
           cout << "Pagado: $" << cantidad << endl;
        }else{
           cout << "Pago rechaado" << endl;
        }
   }



};

int main(){
   
   int aux;
   TarjetaBancaria t1("1234123412341234", "Diana Dominguez", "BanCiencias", 3, 30, 1234);
   
   t1.ActivarTarjeta();
   t1.nombreTarjeta = "Diana Dominguez";
   t1.numTarjeta = "123412341231234";

   return 0;

}
