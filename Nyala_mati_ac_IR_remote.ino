
#include <IRremote.h>

int RECV_PIN = A0;
int relay=13;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(relay,OUTPUT);
  
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume(); // Receive the next value
   
  }
  if(irrecv.decode(948321248)) //nyala 
  {
    digitalWrite(relay,HIGH);
  }
 else if(irrecv.decode(948321232)) {
    digitalWrite(relay,LOW);
  }

}
