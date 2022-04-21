#include <Adafruit_BMP280.h>
#include <BluetoothSerial.h>

const int LED_SENSOR = 34;
const int LED_BT = 32;
const int PHOTO = 35;

Adafruit_BMP280 bmp;
BluetoothSerial SerialBT;

char payload[50];


void setup() {
  Serial.begin(115200);
  SerialBT.begin("BT_ESP32");
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(LED_SENSOR,OUTPUT);
  pinMode(LED_BT,OUTPUT);

  bmp.begin(0x76);
  
}

void loop() {
  digitalWrite(LED_SENSOR,HIGH);
  sprintf(payload,"%04d,%06.2f",analogRead(PHOTO), bmp.readPressure()/100);
  digitalWrite(LED_SENSOR,LOW);
  
  digitalWrite(LED_BT,HIGH); //Prende cuando empieza a escribir
  Serial.println(payload);
  SerialBT.println(payload);
  delay(10);
  
  digitalWrite(LED_BT,LOW); //Apaga el LED cuando termina

  delay(500);

}
