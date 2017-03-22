class ultrasonic {
public:
    bool DEBUG = 1;
    float prevDistance = -100;
    
    float readDistance() {
        digitalWrite(D5, HIGH);
        delayMicroseconds(10);
        digitalWrite(D5, LOW);
        int duration = pulseIn(D6, HIGH);
        float distanceCm = duration*0.034/2;
        float distanceInch = duration*0.0133/2;
        
        if (duration < 10*1000) {
            delayMicroseconds(10*1000 - duration);
            return distanceCm;
        } else {
            return 165;
        }
        
        //delay(11);
    }
    
    float getStableValue() {    
        float distance = readDistance();
        float diff = abs(distance - prevDistance);
        float abDiff = abs(
            (pow(distance, 2) - pow(prevDistance, 2))
            /(distance * prevDistance)
            );
        
        if (diff < 2) {
            if (DEBUG == true) {
                Serial.print(diff);
                Serial.print("d ");
                Serial.print(prevDistance);
            }
            
        } else if (abDiff < 0.5) {
            if (DEBUG == true) {
                Serial.print(abDiff);
                Serial.print(": ");
                Serial.print(prevDistance);
            }
            
        } else {
            prevDistance = distance;
            return -1;
        }

        Serial.print(" ");
        Serial.println(distance);
        
        prevDistance = distance;
        return distance;
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
    };
};



