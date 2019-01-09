#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server;
uint8_t pin_led = D0;

char*ssid ="le2";
char*password="praneet000";
char webpage[] PROGMEM =R"=====(
<html>
<head>
<style>
.button {
  background-color: #008CBA;
  border:none;
  color:white;
  padding: 15px 32px;
  text-align: center;
  font-size: 16px;
  margin: 4px 2px;
  cursor: pointer;
  border-radius: 8px;
}
.text{
  font-size:20px;
}
</style>
</head>
<body>
<p class="text"> LED status:<span id="led-state">__</span></p>
<button class="button" onclick="myFunction()">TOGGLE</button>
</body>
<script>
function myFunction()
{
  console.log("button was clicked!");
  var xhr == new XMLHttpRequset();
  var url = "/ledstate";
  xhr.onreadystatechange = function(){
    if (this.readyState == 4 && this.status  == 200)
    {
      document.getElementById("led-state").innerHTML = this.responseText00
    }
  };
}
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
