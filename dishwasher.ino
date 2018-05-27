
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
//int pinOut = 8;

int solenoidPin = 8;
int pumpPin = 9;
int motorPin = 10;
//int soapPin = 11;

// cicle settings
unsigned long oneMin = 60000;
//unsigned long initTime = oneMin/6;
//unsigned long fillTime = oneMin*2;
//unsigned long washTime = oneMin*42;
//unsigned long drainTime = oneMin;
//unsigned long rinseTime = oneMin*7;

void setup(){
  Serial.begin(9600);
  pinMode(solenoidPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(motorPin, OUTPUT);

  /* Init */

  delay(oneMin/6);
  digitalWrite(pumpPin, HIGH);
  delay(oneMin/6);
  digitalWrite(pumpPin, LOW);

  /* Main */

  //Fill up with water 
  digitalWrite(solenoidPin, HIGH);
  delay(oneMin);
  digitalWrite(solenoidPin, LOW);

  // Start wash
  digitalWrite(motorPin, HIGH);
  delay(oneMin*20);
  digitalWrite(motorPin, LOW);

  // rest
  delay(oneMin);

  // Drain water
  digitalWrite(pumpPin, HIGH);
  delay(oneMin/2);
  digitalWrite(pumpPin, LOW);

  digitalWrite(solenoidPin, HIGH);
  delay(oneMin);
  digitalWrite(solenoidPin, LOW);

  digitalWrite(motorPin, HIGH);
  delay(oneMin*20);
  digitalWrite(motorPin, LOW);

  delay(oneMin);

  digitalWrite(pumpPin, HIGH);
  delay(oneMin/2);
  digitalWrite(pumpPin, LOW);

  //Rinse 1
  digitalWrite(solenoidPin, HIGH);
  delay(oneMin);
  digitalWrite(solenoidPin, LOW);

  digitalWrite(motorPin, HIGH);
  delay(oneMin*5);
  digitalWrite(motorPin, LOW);

  // Drain water
  digitalWrite(pumpPin, HIGH);
  delay(oneMin/2);
  digitalWrite(pumpPin, LOW);

  // rest
  delay(oneMin);

  //Rinse 2
  digitalWrite(solenoidPin, HIGH);
  delay(oneMin/2);
  digitalWrite(solenoidPin, LOW);

  digitalWrite(motorPin, HIGH);
  delay(oneMin*3);
  digitalWrite(motorPin, LOW);

  // Drain water
  digitalWrite(pumpPin, HIGH);
  delay(oneMin);
  digitalWrite(pumpPin, LOW);

  // rest
  delay(oneMin);

  //NOTE 67.5 minutes all up
}
 
void loop() {

}

