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
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// IN ultrasonic pins
#define trigPinU1 2
#define echoPinU1 3

// OUT ultrasonic pins
#define trigPinU2 4
#define echoPinU2 5

// LED and Buzzer pins
#define greenLED 6
#define redLED 7
#define buzzer 8

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

int person = 0;
int lastPerson = 0;

void setup()
{
	// Set serial baudrate for debugging purpose
	Serial.begin(115200);

	// Ultrasonic setup pin
	ultrasonic_setup_pin(trigPinU1, echoPinU1);
	ultrasonic_setup_pin(trigPinU2, echoPinU2);

	// LED and Buzzer setup pin
	pinMode(greenLED, OUTPUT);
	pinMode(redLED, OUTPUT);
	pinMode(buzzer, OUTPUT);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);

	// LCD init
	lcd.begin(16,2);
	lcd.clear();
	lcd.setCursor(0,0);
  	lcd.print(" People Counter ");
	delay(2000);
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

	// Print to LCD display if person changed
	if (person != lastPerson)
	{
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("Total person :");
		lcd.setCursor(0,1);
		lcd.print(person);
	}
	lastPerson = person;

	// Warning status
	if (person >= 10)
	{
		// Red LED ON, green LED OFF
		digitalWrite(greenLED, LOW);
		digitalWrite(redLED, HIGH);

		// Alarm ON
		digitalWrite(buzzer, HIGH);
		delay(1000);
		digitalWrite(buzzer, LOW);
		delay(1000);
	}
	else
	{
		// Green LED ON, red LED OFF
		digitalWrite(redLED, LOW);
		digitalWrite(greenLED, HIGH);
		digitalWrite(buzzer, LOW);
	}
	
}
