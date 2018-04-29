int DASH = 500;
int DOT = 250;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  sos();
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

// the loop function runs over and over again forever
void loop() {

}
