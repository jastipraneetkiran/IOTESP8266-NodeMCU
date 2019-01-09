void setup() {
  // put your setup code here, to run once:
//mode initialise
pinMode(D0,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(D0,HIGH);
Serial.println("LED Off");
delay(1000);
}
