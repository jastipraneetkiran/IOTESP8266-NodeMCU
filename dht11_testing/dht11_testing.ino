#include "DHT.h"
#define DHTPIN D1
#define DHTTYPE DHT11 //DHT11
DHT dht(DHTPIN,DHTTYPE);

void setup(){
  Serial.begin(115200);
  Serial.println("DHT-11 test");

  dht.begin();
}

void loop()
{
  delay(2000);
  float h = dht.readHumidity();

  float f = dht.readTemperature(true);
  if(isnan(h) || isnan(f))
  {
    Serial.println("Failed to read DHT Sensor");
    return;
  }
  Serial.print("humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature");
  Serial.print(f);
  Serial.print(" *F ");
}
