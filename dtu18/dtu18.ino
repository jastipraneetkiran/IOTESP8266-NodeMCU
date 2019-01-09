void setup() {
  // put your setup code here, to run once:
//mode initialise
pinMode(D0,OUTPUT);
pinMode(D5,INPUT);//sensor pin
Serial.begin(9600);

}
int a=0;
void loop() {
  // put your main code here, to run repeatedly:

int sensor_value=digitalRead(D5);

Serial.print("sensor value");
Serial.println(sensor_value);
if(sensor_value == HIGH)
{
  a=a+1;
digitalWrite(D0,LOW);

}
if(sensor_value == LOW)
{
digitalWrite(D0,HIGH);
 
}
Serial.println(a);
delay(1000);
}
