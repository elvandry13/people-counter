#include "ultrasonic.h"

void ultrasonic_setup_pin(const uint8_t trigPin, const uint8_t echoPin)
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

long ultrasonic_measure(const uint8_t trigPin, const uint8_t echoPin)
{    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(8);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(8);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(8);
    long duration = pulseIn(echoPin, HIGH);
    long distance = duration / 58.2;
    return distance;
}

bool ultrasonic_detect(const uint8_t trigPin, const uint8_t echoPin)
{
    int count = 0;

	if (ultrasonic_measure(trigPin, echoPin) < 10)
	{
		for (int i=0; i<=4; i++)
		{
			if (ultrasonic_measure(trigPin, echoPin) < 10)
			{
				count++;
			}
			if (count > 3)
			{
                return true;
			}
			delay(200);
		}
	}
}
