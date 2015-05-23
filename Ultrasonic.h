#ifndef Ultrasonic_H
#define Ultrasonic_H

#include <Energia.h>


class Ultrasonic{
	public:
		Ultrasonic(byte triggerPin, byte echoPin);
		~Ultrasonic();
		void init();
		unsigned int distance(byte mode);

		byte tPin;
		byte ePin;
};

#endif