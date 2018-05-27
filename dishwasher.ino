
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
//int pinOut = 8;

int solenoidPin = 8;
int pumpPin = 9;
int motorPin = 10;
//int soapPin = 11;

// cicle settings
unsigned long oneMin = 60000;
unsigned long initTime = oneMin/6;
unsigned long fillTime = oneMin*2;
unsigned long washTime = oneMin*42;
unsigned long drainTime = oneMin;
unsigned long rinseTime = oneMin*7;

void setup(){
  Serial.begin(9600);
  pinMode(solenoidPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void rinse(int n) {
  //Rinse 1
  digitalWrite(solenoidPin, HIGH);
  delay(fillTime);
  digitalWrite(solenoidPin, LOW);

  digitalWrite(motorPin, HIGH);
  delay(rinseTime/n);
  digitalWrite(motorPin, LOW);

  // Drain water
  digitalWrite(pumpPin, HIGH);
  delay(drainTime);
  digitalWrite(pumpPin, LOW);

  // rest
  delay(oneMin*2);
}

void loop() {

  delay(oneMin/6);

  /* Init */

  digitalWrite(pumpPin, HIGH);
  delay(initTime);
  digitalWrite(pumpPin, LOW);

  /* Main */

  //Fill up with water 
  digitalWrite(solenoidPin, HIGH);
  delay(fillTime);
  digitalWrite(solenoidPin, LOW);

  // Start wash
  digitalWrite(motorPin, HIGH);
  delay(washTime);
  digitalWrite(motorPin, LOW);

  // rest
  delay(oneMin*2);

  // Drain water
  digitalWrite(pumpPin, HIGH);
  delay(drainTime);
  digitalWrite(pumpPin, LOW);
  
  rinse(1);

  rinse(2);

  exit(0);
}

