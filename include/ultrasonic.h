/**
 * @file ultrasonic.h
 * @author Elvandry Ghiffary (elvandry13@gmail.com)
 * @brief Ultrasonic header file
 * @version 0.1
 * @date 2020-07-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Arduino.h"

/**
 * @brief Ultrasonic Setup Pin
 * 
 * @param trigPin Pin of trig
 * @param echoPin Pin of echo
 */
void ultrasonic_setup_pin(const uint8_t trigPin, const uint8_t echoPin);

/**
 * @brief Measure distance from sensor to object
 * 
 * @param trigPin Pin of trig
 * @param echoPin Pin of echo
 * @return Distance in cm
 */
long ultrasonic_measure(const uint8_t trigPin, const uint8_t echoPin);

/**
 * @brief Detecting object
 * 
 * @param trigPin Pin of trig
 * @param echoPin Pin of echo
 * @return true if detected
 * @return false if not detected
 */
bool ultrasonic_detect(const uint8_t trigPin, const uint8_t echoPin);
