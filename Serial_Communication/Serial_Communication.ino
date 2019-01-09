char data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(D2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Serial Controller");
  delay(300);
  if(Serial.available());
  {
    //read te most recent byte
    data= Serial.read();

    if((data== 'W') || (data=='w'))
    {
      digitalWrite(D2,HIGH);
      Serial.print("Data is : ");
      Serial.println(data);
      Serial.println("Moving forward.....");
    }
    if((data== 'D') || (data=='D'))
    {
      digitalWrite(D2,HIGH);
      Serial.print("Data is : ");
      Serial.println(data);
      Serial.println("Moving Right.....");
    }
    if((data== 'A') || (data=='a'))
    {
      digitalWrite(D2,HIGH);
      Serial.print("Data is : ");
      Serial.println(data);
      Serial.println("Moving left.....");
    }
    if((data== 'S') || (data=='s'))
    {
      digitalWrite(D2,HIGH);
      Serial.print("Data is : ");
      Serial.println(data);
      Serial.println("STOP.....");
    }
  }

}
