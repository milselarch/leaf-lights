#include "fader.h"
#include "misc.h"
#include "ultrasonic.h"

void setup() {
    // put your setup code here, to run once:
    Serial.begin(57600);
    delay(3000);
    analogWriteRange(250);
    //pinMode(D0, OUTPUT);

    pinMode(D5, OUTPUT); //ultrasonic trigger pin
    pinMode(D6, INPUT); //ultrasonic echo recieve pin
}

fader fadeController;
float multiplier = 1;
const float factor = 0.88;
float cTotal = 1.0 / (1.0 - factor);

unsigned long inTime = -1;

void loop() {
    // put your main code here, to run repeatedly:
    // fade in from min to max in increments of 5 points
    //fadeInOut();
    //randLED();

    //fadeBlueGreen();

    //Serial.println(getMedianValue());
    //displayRGB(light);

    //float distance = readDistance();
    float distance = getStableValue();
    const int maxDistance = 45;
    const int minDistance = 10;

    if (maxDistance > distance and distance > minDistance) {
        // people detected between max and min distance
        const float base = 0.5;
        /*
        multiplier = base + (
            (distance-minDistance)
            /(maxDistance-minDistance)
            )*(1.0-base)
            ;
        */

        multiplier = 1;
        inTime = millis();
        
    } else if (minDistance > distance) {
        // inside min distance
        multiplier = 1;

        inTime = millis();
        
    } else if (distance > maxDistance) {
        // distance outside max distance
        // multiplier = 0.5;
        multiplier = 1;
    } 
    
    if (millis() - inTime > 1000*20) {
        fadeController.off = true;
    } else {
        fadeController.off = false;
    }

    Serial.println(fadeController.off);
    Serial.println(int(distance));
    if (fadeController.off == false) {
        for (int k = 0; k < 100; k++) {
            fadeController.fadeInOut(30, multiplier);
        }
    } else {
        fadeController.fadeInOut(30, multiplier);  
    }
}


