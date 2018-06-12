
/*

Name: Cool Dishwasher
Author: kizza
Date: 29.05.2018

 */

#define RELAY_ON LOW
#define RELAY_OFF HIGH
#define MAX_TEMP 700

const int pumpPin = 11;     //In1
const int solenoidPin = 10; //In2
const int motorPin = 9;     //In3
const int heaterPin = 8;    //In4
//int soapPin = 11;

int thermistorPin = 0;
int thermistorVal = 0;

unsigned long ONE_SEC = 1000UL;

unsigned long time;

int fillState = 0;
int washState = 0;
int heatState = 0;
int rinseState = 0;
int drainState = 1;
int restState = 0;
int doneState = 0;

void setup() {

  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  pinMode(solenoidPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(heaterPin, OUTPUT);

  digitalWrite(pumpPin, RELAY_OFF);
  digitalWrite(solenoidPin, RELAY_OFF);
  digitalWrite(motorPin, RELAY_OFF);
  digitalWrite(heaterPin, RELAY_OFF);

}

void loop() {
    // time since current program stated running
    time = millis();
    thermistorVal = analogRead(thermistorPin);     // read the input pin

    if(thermistorVal > MAX_TEMP) {
        digitalWrite(heaterPin, RELAY_OFF);
    }

    if(fillState == 1) {
        digitalWrite(pumpPin, RELAY_OFF);
        digitalWrite(solenoidPin, RELAY_ON);
        digitalWrite(motorPin, RELAY_OFF);
        digitalWrite(heaterPin, RELAY_OFF);
        drainState = 0;
    }

    if(washState == 1) {
        digitalWrite(pumpPin, RELAY_OFF);
        digitalWrite(solenoidPin, RELAY_OFF);
        digitalWrite(motorPin, RELAY_ON);

        if(heatState == 1 && thermistorVal < MAX_TEMP) {
            digitalWrite(heaterPin, RELAY_ON);
        }
        else {
            digitalWrite(heaterPin, RELAY_OFF);
        }
        fillState = 0;
    }

    if(drainState == 1) {
        digitalWrite(pumpPin, RELAY_ON);
        digitalWrite(solenoidPin, RELAY_OFF);
        digitalWrite(motorPin, RELAY_OFF);
        digitalWrite(heaterPin, RELAY_OFF);
        restState = 0;
        washState = 0;
        heatState = 0;
    }

    if(restState == 1) {
        digitalWrite(pumpPin, RELAY_OFF);
        digitalWrite(solenoidPin, RELAY_OFF);
        digitalWrite(motorPin, RELAY_OFF);

        if(heatState == 1 && thermistorVal < MAX_TEMP) {
            digitalWrite(heaterPin, RELAY_ON);
        }
        else {
            digitalWrite(heaterPin, RELAY_OFF);
        }

        fillState = 0;
        washState = 0;
        rinseState = 0;
        drainState = 0;
    }

    if(doneState == 1) {
        digitalWrite(pumpPin, RELAY_OFF);
        digitalWrite(solenoidPin, RELAY_OFF);
        digitalWrite(motorPin, RELAY_OFF);
        digitalWrite(heaterPin, RELAY_OFF);
        fillState = 0;
        washState = 0;
        rinseState = 0;
        restState = 0;
        drainState = 0;
        heatState = 0;
    }

    if(time > ONE_SEC*30 && time < ONE_SEC*120) {
        fillState = 1;
    }
    //1800 secs == 30 minutes
    if(time > ONE_SEC*120 && time < ONE_SEC*2400) {
        washState = 1;
    }

    if(time > ONE_SEC*2460 && time < ONE_SEC*3330) {
        heatState = 1;
    }

    if(time > ONE_SEC*2430 && time < ONE_SEC*3330) {
        restState = 1;
    }
    
    if(time > ONE_SEC*2900 && time < ONE_SEC*3330) {
        heatState = 0;
    }

    if(time > ONE_SEC*3330 && time < ONE_SEC*3410) {
        drainState = 1;
    }

    if(time > ONE_SEC*3410 && time < ONE_SEC*3530) {
        fillState = 1;
    }

    //3000 secs == 50 minutes
    if(time > ONE_SEC*3530 && time < ONE_SEC*4130) {
        washState = 1;
        heatState = 1;
    }
    // wait for five minutes for water to heat up
    // this will dry dishers quicker
    if(time > ONE_SEC*4130 && time < ONE_SEC*4430) {
        restState = 1;
        heatState = 1;
    }

    if(time > ONE_SEC*4430 && time < ONE_SEC*4515) {
        drainState = 1;
    }

    if(time > ONE_SEC*4515) {
        doneState = 1;
    }
}

