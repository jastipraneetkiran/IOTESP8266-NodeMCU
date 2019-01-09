#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server;
uint8_t pin_led = D0;

char*ssid ="le2";
char*password="praneet000";

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_led,OUTPUT);
WiFi.begin(ssid,password);
Serial.begin(115200);
while(WiFi.status()!=WL_CONNECTED)
{
  Serial.print(".");
  delay(500);
}
Serial.println("");
Serial.print("IF Address: ");
Serial.print(WiFi.localIP());
server.on("/",[](){server.send(200,"text/html","Hello World!");});
server.on("/toggle",toggleLED);
server.begin();
//copy the ip from the serial moniter and open it check in browser
}

void loop() {
  // put your main code here, to run repeatedly:
server.handleClient(); //the handle will show errors
}
void toggleLED()
{
  digitalWrite(pin_led,!digitalRead(pin_led));
  server.send(204,"");//"ip address/toggle"
}
