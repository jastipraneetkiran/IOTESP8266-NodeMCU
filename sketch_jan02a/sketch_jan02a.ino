char data;

void setup() {
  // put your setup code here, to run once:
Serial.(begn(9600);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Serial Controller");
delay(300);
if(Serial.available())
{
  data = Serial.read();
if((data == 'W') || (data == 'w'))
{
  digitalWrite(D2,HIGH);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  digitalWrite(D5,HIGH);
  Serial.print("DATA is :  ");
  Serial.println(data);
  Serial.println("MOVING LEFT....")
}
}
}
