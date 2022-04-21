#include <Adafruit_BMP280.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

const int LED_SENSOR = 34;
const int LED_BT = 32;
const int PHOTO = 35;

Adafruit_BMP280 bmp;
BluetoothSerial SerialBT;
boolean confirmRequestPending = true;

char payload[50];

void BTConfirmRequestCallback(uint32_t numVal)
{
  confirmRequestPending = true;
  Serial.println(numVal);
  Serial.println("Do you consent?");
}

void BTAuthCompleteCallback(boolean success)
{
  confirmRequestPending = false;
  if (success)
  {
    Serial.println("Pairing success!!");
  }
  else
  {
    Serial.println("Pairing failed, rejected by user!!");
  }
}

void setup() {
  Serial.begin(115200);
  SerialBT.enableSSP();
  SerialBT.onConfirmRequest(BTConfirmRequestCallback);
  SerialBT.onAuthComplete(BTAuthCompleteCallback);
  SerialBT.begin("BT_ESP32");
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(LED_SENSOR,OUTPUT);
  pinMode(LED_BT,OUTPUT);

  bmp.begin(0x76);

}

void loop() {

 if (confirmRequestPending)
  {
    if (Serial.available())
    {
      int dat = Serial.read();
      if (dat == 'Y' || dat == 'y')
      {
        SerialBT.confirmReply(true);
      }
      else
      {
        SerialBT.confirmReply(false);
      }
    }
  }
  else
  {
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
}
