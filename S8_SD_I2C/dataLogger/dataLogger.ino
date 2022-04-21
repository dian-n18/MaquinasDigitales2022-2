#include <SD.h>
#include <Adafruit_BMP280.h>

File archivo;

const int LED_SENSOR = 34;
const int LED_SD = 32;
const int PHOTO = 35;

Adafruit_BMP280 bmp;

char payload[50];

void setup() {
  Serial.begin(115200);
  SD.begin();

  pinMode(LED_SENSOR,OUTPUT);
  pinMode(LED_SD,OUTPUT);

  bmp.begin(0x76);

  archivo = SD.open("/Luz_Presion_2.csv", FILE_APPEND);
  archivo.println("Luz[adim],Presion[hPa]");
  
}

void loop() {
  
  digitalWrite(LED_SENSOR,LOW);
  sprintf(payload,"%04d,%06.2f",analogRead(PHOTO), bmp.readPressure()/100);
  
//  payload = analogRead(PHOTO):
  digitalWrite(LED_SD,HIGH); //Prende cuando empieza a escribir
  delay(10);
  Serial.println(payload);
  archivo = SD.open("/Luz_Presion.csv",FILE_APPEND);
  archivo.println(payload);
 // archivo.close();
  digitalWrite(LED_SD,LOW); //Apaga el LED cuando termina

  delay(500);
}
