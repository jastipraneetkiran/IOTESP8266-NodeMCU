#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;
uint8_t pin_led = D1;
char* ssid = "Autobots";
char* password = "123456789";

char webpage[] PROGMEM = R"=====(
<html>
<head>
<style>
.button {
    background-color: #008CBA;        /* Green */
    border: none;
    color: white;
    padding: 15px 32px;
    text-align: center;
    font-size: 16px;
    margin: 4px 2px;
    cursor: pointer;
    border-radius: 8px;}
.text{
  font-size: 20px;
  }
    
</style>
</head>
<body>
<p class="text"> LED Status: <span id="led-state">__</span> </p>
<button class="button" onclick="myFunction()"> TOGGLE </button>
</body>
<script>
function myFunction()
{
  console.log("button was clicked!");
  var xhr = new XMLHttpRequest();          //Instanciate XMLHttpRequest() class , and create object which will allow us to use asynchronus java script to send a request to the server 
  var url = "/ledstate";
  xhr.onreadystatechange = function() {    // call into action when a button is press 
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("led-state").innerHTML = this.responseText;
    }
  };
  xhr.open("GET", url, true);
  xhr.send();
};
document.addEventListener('DOMContentLoaded', myFunction, false);     //adding here addEventListener event , means above function runs whenevr page will load/ not compatible for all browser 
</script>
</html>
)=====";

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

  server.on("/",[](){server.send_P(200,"text/html", webpage);});
  server.on("/ledstate",getLEDState);
  server.begin();
}

void loop()
{
  server.handleClient();
}

void toggleLED()
{
  digitalWrite(pin_led,!digitalRead(pin_led));
}

void getLEDState()
{
  toggleLED();
  String led_state = digitalRead(pin_led) ? "ON" : "OFF";
  server.send(200,"text/plain", led_state);
}
