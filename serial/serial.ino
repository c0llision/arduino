String incoming = "";
int DOT = 250;
int DASH = 500;


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void flash(int t)
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);    
  digitalWrite(LED_BUILTIN, LOW); 
  delay(t);
}

void sos()
{
  flash(DOT);
  flash(DOT);
  flash(DOT);
  delay(500);
  flash(DASH);
  flash(DASH);
  flash(DASH);
  delay(500);
  flash(DOT);
  flash(DOT);
  flash(DOT);
  delay(1000);
}


void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    //we have received a message
    incoming = Serial.readString();
    
    if (incoming == "on")
    {
      Serial.write("Switching on LED\n");
      digitalWrite(13, HIGH);
    }
    else if (incoming == "sos")
    {
      
      Serial.write("Doing SOS\n");
      digitalWrite(LED_BUILTIN, LOW); 
      delay(500);
      sos();
    }
    else if (incoming == "off")
    {
      Serial.write("Switching off LED\n");
      digitalWrite(13, LOW);
    }
    else
    {
      Serial.write("Commands: on, off, sos\n");
    }
  }
}


