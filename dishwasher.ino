
/*

Name: Smart Dishwasher
Author: kizza
Date: 29.05.2018

 */

const int solenoidPin = 8;
const int pumpPin = 9;
const int motorPin = 10;
//int soapPin = 11;

const unsigned long ONE_SEC = 1000UL;
const unsigned long TWENTY_SEC = 20UL * ONE_SEC;
const unsigned long THIRTY_SEC = 35UL * ONE_SEC;
const unsigned long ONE_MIN = 60UL * ONE_SEC;
const unsigned long TWO_MIN = 120UL * ONE_SEC;
const unsigned long THREE_MIN = 180UL * ONE_SEC;
const unsigned long ONE_N_HALF_MIN = 100UL * ONE_SEC; // I know that this is not minute and half!
const unsigned long FIVE_MIN = 5UL * ONE_MIN;
const unsigned long THIRTEEN_MIN = 13UL * ONE_MIN;
const unsigned long THIRTY_MIN = 30UL * ONE_MIN;
const unsigned long ONE_HOUR = 60UL * ONE_MIN;

void driveRelay(const int relayPin, const unsigned long cycleTime) {

  digitalWrite(relayPin, HIGH);
  delay(cycleTime);
  digitalWrite(relayPin, LOW);

}

void setup() {

  Serial.begin(9600);
  pinMode(solenoidPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(motorPin, OUTPUT);

}

void loop() {
  /* Init */

  delay(THIRTY_SEC);
  driveRelay(pumpPin, THIRTY_SEC);

  /* Main */

  // Cycle 1

  // fill up
  driveRelay(solenoidPin, ONE_N_HALF_MIN);
  // wash
  driveRelay(motorPin, THIRTY_MIN);
  // rest
  delay(ONE_MIN);
  // drain
  driveRelay(pumpPin, THIRTY_SEC);

  // Cycle 2

  // fill up
  driveRelay(solenoidPin, ONE_N_HALF_MIN);
  // wash
  driveRelay(motorPin, THIRTY_MIN);
  // rest
  delay(THIRTEEN_MIN);
  // drain
  driveRelay(pumpPin, THIRTY_SEC);

  /* Rinse */

  // Rinse 1

  // fill up
  driveRelay(solenoidPin, ONE_N_HALF_MIN);
  // rinse
  driveRelay(motorPin, FIVE_MIN);
  // drain
  driveRelay(pumpPin, ONE_MIN);
  // rest
  delay(TWO_MIN);

  // Rinse 2

  // fill up
  driveRelay(solenoidPin, ONE_N_HALF_MIN);
  // rinse
  driveRelay(motorPin, THREE_MIN);
  // drain
  driveRelay(pumpPin, ONE_N_HALF_MIN);

  while(1);
}

