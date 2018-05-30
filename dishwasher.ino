
/*

Name: Cool Dishwasher
Author: kizza
Date: 29.05.2018

 */

const int solenoidPin = 8;
const int pumpPin = 9;
const int motorPin = 10;
//int soapPin = 11;

unsigned long ONE_SEC = 1000UL;

unsigned long time;

int fillState = 0;
int washState = 0;
int rinseState = 0;
int drainState = 1;
int restState = 0;
int doneState = 0;

void setup() {

  Serial.begin(9600);
  pinMode(solenoidPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(motorPin, OUTPUT);

}

void loop() {
    // time since current program stated running
    time = millis();

    if(fillState == 1) {
        digitalWrite(solenoidPin, HIGH);
        digitalWrite(pumpPin, LOW);
        digitalWrite(motorPin, LOW);
        drainState = 0;
    }

    if(washState == 1) {
        digitalWrite(solenoidPin, LOW);
        digitalWrite(pumpPin, LOW);
        digitalWrite(motorPin, HIGH);
        fillState = 0;
    }

    if(drainState == 1) {
        digitalWrite(solenoidPin, LOW);
        digitalWrite(pumpPin, HIGH);
        digitalWrite(motorPin, LOW);
        restState = 0;
        washState = 0;
    }

    if(restState == 1) {
        digitalWrite(solenoidPin, LOW);
        digitalWrite(pumpPin, LOW);
        digitalWrite(motorPin, LOW);
        fillState = 0;
        washState = 0;
        rinseState = 0;
        drainState = 0;
    }

    if(doneState == 1) {
        digitalWrite(solenoidPin, LOW);
        digitalWrite(pumpPin, LOW);
        digitalWrite(motorPin, LOW);
        fillState = 0;
        washState = 0;
        rinseState = 0;
        restState = 0;
        drainState = 0;
    }

    if(time > ONE_SEC*30 && time < ONE_SEC*100) {
        fillState = 1;
    }
    //1800 secs == 30 minutes
    if(time > ONE_SEC*100 && time < ONE_SEC*1800) {
        washState = 1;
    }

    if(time > ONE_SEC*1830 && time < ONE_SEC*2580) {
        restState = 1;
    }

    if(time > ONE_SEC*2580 && time < ONE_SEC*2610) {
        drainState = 1;
    }

    if(time > ONE_SEC*2610 && time < ONE_SEC*2700) {
        fillState = 1;
    }

    //3000 secs == 50 minutes
    if(time > ONE_SEC*2700 && time < ONE_SEC*3000) {
        washState = 1;
    }

    if(time > ONE_SEC*3000 && time < ONE_SEC*3120) {
        restState = 1;
    }

    if(time > ONE_SEC*3120 && time < ONE_SEC*3150) {
        drainState = 1;
    }

    if(time > ONE_SEC*3150) {
        doneState = 1;
    }
}

