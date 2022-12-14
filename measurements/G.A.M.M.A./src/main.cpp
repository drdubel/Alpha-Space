#include <Adafruit_L3GD20_U.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <Wire.h>

HardwareSerial mySerial(PB11, PB10);

Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);

void displaySensorDetails(void) {
    sensor_t sensor;
    gyro.getSensor(&sensor);
    mySerial.println("------------------------------------");
    mySerial.print("Sensor:       ");
    mySerial.println(sensor.name);
    mySerial.print("Driver Ver:   ");
    mySerial.println(sensor.version);
    mySerial.print("Unique ID:    ");
    mySerial.println(sensor.sensor_id);
    mySerial.print("Max Value:    ");
    mySerial.print(sensor.max_value);
    mySerial.println(" rad/s");
    mySerial.print("Min Value:    ");
    mySerial.print(sensor.min_value);
    mySerial.println(" rad/s");
    mySerial.print("Resolution:   ");
    mySerial.print(sensor.resolution);
    mySerial.println(" rad/s");
    mySerial.println("------------------------------------");
    mySerial.println("");
    delay(500);
}

void setup(void) {
    mySerial.begin(115200);
    mySerial.println("Gyroscope Test");
    mySerial.println("");
    gyro.enableAutoRange(true);
    if (!gyro.begin()) {
        mySerial.println("Ooops, no L3GD20 detected ... Check your wiring!");
        while (1)
            ;
    }
    displaySensorDetails();
}

void loop(void) {
    sensors_event_t event;
    gyro.getEvent(&event);
    mySerial.print("X: ");
    mySerial.print(event.gyro.x);
    mySerial.print("  ");
    mySerial.print("Y: ");
    mySerial.print(event.gyro.y);
    mySerial.print("  ");
    mySerial.print("Z: ");
    mySerial.print(event.gyro.z);
    mySerial.print("  ");
    mySerial.println("rad/s ");
    delay(500);
}