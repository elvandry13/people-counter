#include "Arduino.h"

void ultrasonic_setup_pin(const uint8_t trigPin, const uint8_t echoPin);

long ultrasonic_measure(const uint8_t trigPin, const uint8_t echoPin);

bool ultrasonic_detect(const uint8_t trigPin, const uint8_t echoPin);
