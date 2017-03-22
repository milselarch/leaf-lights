#include "fader.h"
#include "misc.h"
#include "ultrasonic.h"

/*
float multiplier = 1;
const float factor = 0.88;
float cTotal = 1.0 / (1.0 - factor);
*/

fader fadeController;
ultrasonic distSensor;

unsigned long inTime = -1;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(57600);
    delay(3000);
    analogWriteRange(250);
    //pinMode(D0, OUTPUT);

    pinMode(D5, OUTPUT); //ultrasonic trigger pin
    pinMode(D6, INPUT); //ultrasonic echo recieve pin
}

void loop() {
    //float distance = readDistance();
    float distance = distSensor.getStableValue();

    if (distance != -1) {
        const int maxDistance = 45;
        if (maxDistance > distance) {
            // people detected between max and min distance
            inTime = millis();   
        }
    }
    
    if (millis() - inTime > 1000*20) {
        fadeController.off = true;
    } else {
        fadeController.off = false;
    }

    //Serial.println(fadeController.off);
    fadeController.fadeInOut(0, 1); 
}


