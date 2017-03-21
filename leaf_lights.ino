unsigned int fadeValue = 0;
bool fadeIn = false;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(57600);
    delay(3000);

    analogWriteRange(255);
    //pinMode(D0, OUTPUT);

    pinMode(D5, OUTPUT);
    pinMode(D6, INPUT);
}


class fadeInOut {
    void fadeInOut() {
        for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
            analogWrite(D1, fadeValue);
            delay(30);
        }
        for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
            analogWrite(D1, fadeValue);
            delay(30);
        }
    
        for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
            analogWrite(D2, fadeValue);
            delay(30);
        }
        for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
            analogWrite(D2, fadeValue);
            delay(30);
        }
    
        for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
            analogWrite(D3, fadeValue);
            delay(30);
        }
        for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
            analogWrite(D3, fadeValue);
            delay(30);
        }
    }
}

void fadeBlueGreen() {
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
        // sets the value (range from 0 to 255):
        analogWrite(D1, fadeValue);
        analogWrite(D2, 255 - fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(30);
    }
    
    // fade out from max to min in increments of 5 points:
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
        // sets the value (range from 0 to 255):
        analogWrite(D1, fadeValue);
        analogWrite(D2, 255 - fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(30);
    }
}

void randLED() {
    analogWrite(D0, random(0,255)/1.5);
    analogWrite(D1, random(0,255)/1.5);
    analogWrite(D2, random(0,255));
    delay(30);
}

void loop() {
    // put your main code here, to run repeatedly:
    // fade in from min to max in increments of 5 points
    //fadeInOut();
    randLED();

    digitalWrite(D5, HIGH);
    delayMicroseconds(10);
    digitalWrite(D5, LOW);
    int duration = pulseIn(D6, HIGH);
    float distanceCm = duration*0.034/2;
    float distanceInch = duration*0.0133/2;

    Serial.println(distanceCm);
    delay(10);
}


