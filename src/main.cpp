#include <Arduino.h>
#include "ultrasonic.h"

#define trigPinU1 2
#define echoPinU1 3

#define trigPinU2 4
#define echoPinU2 5

int person = 0;

void setup()
{
	Serial.begin(115200);
	ultrasonic_setup_pin(trigPinU1, echoPinU1);
	ultrasonic_setup_pin(trigPinU2, echoPinU2);
}

void loop()
{
	if (ultrasonic_detect(trigPinU1, echoPinU1))
	{
		person++;
		Serial.println(person);
	}
	if (ultrasonic_detect(trigPinU2, echoPinU2))
	{
		person--;
		Serial.println(person);
	}
}
