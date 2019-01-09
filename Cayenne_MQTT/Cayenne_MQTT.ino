#include "CayenneMQTTESP8266.h"
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial

#include "DHT.h"

#define DHTPIN D2     

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

char ssid[]="iot";
char password[] ="iot12345";

char username[] = "07e5f690-9ff7-11e8-af33-cfeebe848e6e";
char mqtt_password[] = "12900a7e1af73b46dd2968faeb1ead15a882efde";
char client_id[] = "58988850-9ff7-11e8-8620-5f550c229a17";

void setup() {
  // put your setup code here, to run once:
  
Cayenne.begin(username,mqtt_password,client_id,ssid,password);

pinMode(D1,OUTPUT);
digitalWrite(D1,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
Cayenne.loop();

// Read temperature as Fahrenheit (isFahrenheit = true)
float temp = dht.readTemperature(true);
float hum = dht.readHumidity();

Cayenne.virtualWrite(1,temp,TYPE_TEMPERATURE,UNIT_FAHRENHEIT);   // 1- Channel ID for TEMP

Cayenne.virtualWrite(2,hum,TYPE_RELATIVE_HUMIDITY,UNIT_PERCENT);  //2- Channel ID for HUM

}
CAYENNE_IN(0)
{
  digitalWrite(D1,getValue.asInt());
  }
