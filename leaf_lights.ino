#include <ESP8266WiFi.h>

void setup() {
    // put your setup code here, to run once:
    Serial.begin(57600);
    delay(3000);

    analogWriteRange(255);
    //pinMode(D0, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    // fade in from min to max in increments of 5 points
    
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
        // sets the value (range from 0 to 255):
        analogWrite(D0, fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(30);
    }

    Serial.println("test");
    
    // fade out from max to min in increments of 5 points:
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
        // sets the value (range from 0 to 255):
        analogWrite(D0, fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(30);
    }
}
