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
    fadeInOut() {
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
};

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

void sort(float a[], int size) {
    for (int i=0; i<(size-1); i++) {
        for (int o = 0; o < (size-(i+1)); o++) {
            if (a[o] > a[o+1]) {
                float t = a[o];
                a[o] = a[o+1];
                a[o+1] = t;
            }
        }
    }
}

float readDistance() {
    digitalWrite(D5, HIGH);
    delayMicroseconds(10);
    digitalWrite(D5, LOW);
    int duration = pulseIn(D6, HIGH);
    float distanceCm = duration*0.034/2;
    float distanceInch = duration*0.0133/2;
    delay(11);

    return distanceCm;
}

float getStableValue() {
    float prevDistance = -100;
    
    while (true) {
        float distance = readDistance();
        if (abs(distance - prevDistance) < 2) {
            return distance;
        } else {
            prevDistance = distance;    
        }     
    }
}



void displayRGB(int RGB) {
    int blue = 63 * (RGB % 4);
    RGB /= 4;
   
    int green = 31 * (RGB % 8);
    RGB /= 8;

    int red = 31 * (RGB % 8);

    analogWrite(D1, blue);
    analogWrite(D2, red);
    analogWrite(D3, green);
}

void loop() {
    // put your main code here, to run repeatedly:
    // fade in from min to max in increments of 5 points
    //fadeInOut();
    //randLED();

    fadeBlueGreen();

    //Serial.println(getMedianValue());

    //float light = getStableValue();
    //displayRGB(light);

    

    /*
    if (8 > light) {
        analogWrite(D1, int(light*31));
        analogWrite(D2, 0);
        analogWrite(D3, 0);
    } else if (32 > light) {
        analogWrite(D2, int(light*7));
        analogWrite(D1, 0);
        analogWrite(D3, 0);
    } else if (255 > light) {
        analogWrite(D3, int(light));
        analogWrite(D1, 0);
        analogWrite(D2, 0);
    } else {
        analogWrite(D3, 255);
        analogWrite(D1, 0);
        analogWrite(D2, 0);
    }
    */
    
    //Serial.println(int(light));
}


