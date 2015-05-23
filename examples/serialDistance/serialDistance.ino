#include <Ultrasonic.h>

unsigned int x;
Ultrasonic ping(8, 7); //Trigger Pin, Echo Pin	

void setup(){
  Serial.begin(9600);
  ping.init();
}

void loop(){
	
  x = ping.distance(1); //Measure distance in mode 1
  Serial.println(x);
  delay(10);
  /*
    Mode
      0 = echo time (microseconds)
      1 = distance in cm.
  */
}