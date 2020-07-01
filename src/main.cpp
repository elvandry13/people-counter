/**
 * @file main.cpp
 * @author Elvandry Ghiffary (elvandry13@gmail.com)
 * @brief People counter main file
 * @version 0.1
 * @date 2020-07-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <Arduino.h>
#include "ultrasonic.h"

// IN ultrasonic pins
#define trigPinU1 2
#define echoPinU1 3

// OUT ultrasonic pins
#define trigPinU2 4
#define echoPinU2 5

int person = 0;

void setup()
{
	// Set serial baudrate for debugging purpose
	Serial.begin(115200);

	// Ultrasonic setup pin
	ultrasonic_setup_pin(trigPinU1, echoPinU1);
	ultrasonic_setup_pin(trigPinU2, echoPinU2);
}

void loop()
{
	// Count up if person detected enter the room
	if (ultrasonic_detect(trigPinU1, echoPinU1))
	{
		person++;
		Serial.println(person);
	}

	// Count down if person detected exit the room
	if (ultrasonic_detect(trigPinU2, echoPinU2))
	{
		person--;
		Serial.println(person);
	}
}
