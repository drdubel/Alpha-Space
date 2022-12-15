#include <Adafruit_L3GD20_U.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <Wire.h>

Adafruit_L3GD20 gyro;

void setup() {
    Serial.begin(115200);
    if (!gyro.begin()) {
        Serial.println(
            "Oops ... unable to initialize the L3GD20. Check your wiring!");
        while (1)
            ;
    } else {
        Serial.println(
            "Yaaay ... able to initialize the L3GD20. Don't check your "
            "wiring!");
    }
}

void loop() {
    if (Serial.available() > 0) {
        Serial.print((char)Serial.read());
    }
    gyro.read();
    Serial.print("X: ");
    Serial.print((int)gyro.data.x);
    Serial.print(" ");
    Serial.print("Y: ");
    Serial.print((int)gyro.data.y);
    Serial.print(" ");
    Serial.print("Z: ");
    Serial.println((int)gyro.data.z);
    Serial.print(" ");
    delay(100);
}