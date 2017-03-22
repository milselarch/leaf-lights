class fadeInOut {
    unsigned int fadeValue = 0;
    
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

class fader {
public:
    bool off = false;
    bool makeBrighter = true;
    int fadeValue = 250;

    int maxValue = 250;
    int minValue = 0;

    void fadeInOut(int delayMs, float multiplier) {
        if (multiplier > 1) { multiplier = 1; }
        if (multiplier < 0) { multiplier = 0; }
        
        if (fadeValue <= this->minValue) {
            makeBrighter = true;
            if (this->off == true) {
                analogWrite(D1, this->minValue);
                delay(delayMs);
                return;
            }
            
        } else if (fadeValue >= this->maxValue) {
            makeBrighter = false;
        }

        if (makeBrighter) {
            fadeValue += 5;    
        } else {
            fadeValue -= 5;
        }

        if (fadeValue > this->maxValue) { fadeValue = this->maxValue; }
        if (fadeValue < this->minValue) { fadeValue = this->minValue; }

        float finalValue = fadeValue * multiplier;
        //Serial.print("light: ");
        //Serial.println(finalValue);
        analogWrite(D1, finalValue);
        delay(delayMs);
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


