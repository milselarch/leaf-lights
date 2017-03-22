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

float prevDistance = -100;

float getStableValue() {    
    float distance = readDistance();

    while (true) {
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
};


