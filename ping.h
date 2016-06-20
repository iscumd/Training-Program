#ifndef _PINGNEW_H_
#define _PINGNEW_H_
#include <Arduino.h>

class Ping {
	public:
		Ping(int Echo, int Trig);
		Ping(int Echo, int Trig, int Temp);
		float getTemp(char measure);
		float Sample();
		float Poll(int iterations, int delay);
		float toInches(float convert);
	private:
		int _Echo;
		int _Trig;
		int _Temp;
};

#endif