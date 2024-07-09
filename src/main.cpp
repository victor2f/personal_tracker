#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.print("Serial start!\n");

    Serial2.begin(9600);
    Serial.print("Reading GPS!\n");
}

void loop() {
    while (Serial2.available()) {
        char c = Serial2.read();
            Serial.print(c);
    }
}
