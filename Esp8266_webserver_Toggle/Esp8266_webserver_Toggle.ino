#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;

uint8_t pin_led = D0;

char* ssid = "Autobots2";
char* password = "1234567890";

void setup()
{
  pinMode(pin_led, OUTPUT);
  
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
  
// Rout to the webserver , use on() method to add the rout (by adding default rout using "/" )
// and sending a string use [](){server.send(200,"text/html", "Hello World!");}   -- 200 is a response of server , type of text , data/string

    server.on("/",[](){server.send(200,"text/html", "Hello World!");});
    server.on("/toggle",toggleLED);
    server.begin();   // start server 
}

  void loop()
{
    server.handleClient();   // monitor the request on server 
}
void toggleLED()
{
    digitalWrite(pin_led,!digitalRead(pin_led));           // toggle led 
    server.send(204,"");                                  // page not found
}
