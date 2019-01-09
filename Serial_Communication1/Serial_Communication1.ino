
char data;

void setup() {                
// Turn the Serial Protocol ON
  Serial.begin(9600);
}

void loop()
{
    /*  check if data has been sent from the computer: */
    if (Serial.available())
    {
    /* read the most recent byte */     
    data = Serial.read();
    Serial.print("Serial Data is : ");
    Serial.println(data);
    if ((data == 'W') || (data == 'w'))
    { 
     Serial.println("Moving Fwd...");
    }
    
    else if ((data == 'A') || (data == 'a'))
    {    
     Serial.println("Moving Left...");
    }
       
    else if ((data == 'D') || (data == 'd'))
    {    
     Serial.println("Moving Right...");
    }
        else if ((data == 'Z') || (data == 'z'))
    {
     Serial.println("Moving Back...");
    }
     else
     { 
      Serial.println("STOP");
     }
    }
    
}


