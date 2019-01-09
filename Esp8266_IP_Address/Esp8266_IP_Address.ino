#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

char* ssid = "Autobots2";
char* password = "1234567890";

void setup()
{
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

  void loop()
{
}
