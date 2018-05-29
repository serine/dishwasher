
int solenoidPin = 8;
int pumpPin = 9;
int motorPin = 10;
//int soapPin = 11;

unsigned long oneMin = 60000;

void setup(){
  Serial.begin(9600);
  pinMode(solenoidPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  /* Init */

  delay(oneMin/3);
  digitalWrite(pumpPin, HIGH);
  delay(oneMin/3);
  digitalWrite(pumpPin, LOW);

  /* Main */

  //Fill up with water 
  digitalWrite(solenoidPin, HIGH);
  delay(oneMin*1.5);
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
  delay(oneMin*1.5);
  digitalWrite(solenoidPin, LOW);

  digitalWrite(motorPin, HIGH);
  delay(oneMin*20);
  digitalWrite(motorPin, LOW);

  delay(oneMin*13);

  digitalWrite(pumpPin, HIGH);
  delay(oneMin/2);
  digitalWrite(pumpPin, LOW);

  /* Rinse */

  // Rinse 1
  digitalWrite(solenoidPin, HIGH);
  delay(oneMin*1.5);
  digitalWrite(solenoidPin, LOW);

  digitalWrite(motorPin, HIGH);
  delay(oneMin*5);
  digitalWrite(motorPin, LOW);

  // Drain water
  digitalWrite(pumpPin, HIGH);
  delay(oneMin/2);
  digitalWrite(pumpPin, LOW);

  // rest
  delay(oneMin*2);

  //Rinse 2
  digitalWrite(solenoidPin, HIGH);
  delay(oneMin);
  digitalWrite(solenoidPin, LOW);

  digitalWrite(motorPin, HIGH);
  delay(oneMin*3);
  digitalWrite(motorPin, LOW);

  // Drain water
  digitalWrite(pumpPin, HIGH);
  delay(oneMin*1.5);
  digitalWrite(pumpPin, LOW);

  // Stop washing cycle
  while(1);
}

