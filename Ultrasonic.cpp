#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(byte triggerPin, byte echoPin){
	tPin = triggerPin;	
	ePin = echoPin;
}

Ultrasonic::~Ultrasonic(){ //Destructor: do nothing
	;
}

void Ultrasonic::init(){
	pinMode(tPin, OUTPUT);
	digitalWrite(tPin, 0);
	pinMode(ePin, INPUT);
}

unsigned int Ultrasonic::distance(byte mode){
	/*
		Mode
			0 = echo time (microseconds)
			1 = distance in cm.
	*/

	long duration;
	unsigned int distance;

	digitalWrite(tPin, 0);
	delayMicroseconds(2);

	digitalWrite(tPin, 1);
	delayMicroseconds(10);

	digitalWrite(tPin, 0);
	duration = pulseIn(ePin, 1);

	if(!mode){
		return (unsigned int) duration;
	}

	distance = duration * 10 / 582;
	return distance;

}