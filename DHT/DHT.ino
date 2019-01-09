//ESP8266 Interfaced with DHT11 Sensor Data to THINGSPEAK
#include <DHT.h> //  DHT.h library
#include <ESP8266WiFi.h> // ESP8266WiFi.h library

#define DHTPIN D4 //variable storing D4
#define DHTTYPE  DHT11 

const char* ssid     = "Nexus5";
const char* password = "12345678";
const char* host = "api.thingspeak.com";
const char* writeAPIKey = "TMWR47CL9G5PTZHM";

DHT dht(DHTPIN, DHTTYPE); //Intialization of DHT11

void setup() {
  // Initialize sensor
 Serial.begin(115200); //Intization of Serial Communication
 dht.begin(); //To start the DHT11 Sensor
 delay(1000);

  //  Connect to WiFi network
  WiFi.begin(ssid, password); //Connecting Device to WiFi
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
  }
}

void loop() {
 float humidity = dht.readHumidity();  //Storing the Humidity
 float temperature = dht.readTemperature(); // Storing the Temperature
 Serial.println(humidity);
 Serial.println(temperature);
  if (isnan(humidity) || isnan(temperature)) {
    return;
  }

// make TCP connections
  WiFiClient client;
  const int httpPort = 80; 
  if (!client.connect(host, httpPort)) {
    return;
  }

  String url = "/update?key=";
  url+=writeAPIKey;
  url+="&field1=";
  url+=String(humidity);
  url+="&field2=";
  url+=String(temperature);
  url+="\r\n";
  
  // Request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
    delay(3000);
}
