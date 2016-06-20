#include <ping.h>

Ping::Ping(int Echo, int Trig) {
	pinMode(Echo, INPUT);
	pinMode(Trig, OUTPUT);
	_Echo = Echo;
	_Trig = Trig;
	_Temp = -1;
}

Ping::Ping(int Echo, int Trig, int Temp) {
	pinMode(Echo, INPUT);
	pinMode(Trig, OUTPUT);
	pinMode(Temp, INPUT);
	_Echo = Echo;
	_Trig = Trig;
	_Temp = Temp;
}

float Ping::getTemp(char measure) {
	float temp = (((analogRead(_Temp) * 5 / 1024.0) - 0.5) / 0.01);
	switch(measure) {
		case 'f':case 'F':
			temp = 1.8 * temp + 32;
			break;
		case 'k':case 'K':
			temp += 273.15;
			break;
		default:;
	}
	
	return temp;
}

float Ping::Sample() {
	if(_Temp != -1) {
		float tempK = getTemp('k');
		float cSound = pow((1.4 * 8.314)/(.02895), 0.5) * pow(tempK, 0.5);
		digitalWrite(_Trig, LOW);
		delayMicroseconds(2);
		digitalWrite(_Trig, HIGH);
		delayMicroseconds(10);
		digitalWrite(_Trig, LOW);
		unsigned long duration = pulseIn(_Echo, HIGH);
		float distanceCm = (duration * cSound) / 20000;
		return distanceCm;
	} else {
		float cSound = 10000 / 29;
		digitalWrite(_Trig, LOW);
		delayMicroseconds(2);
		digitalWrite(_Trig, HIGH);
		delayMicroseconds(10);
		digitalWrite(_Trig, LOW);
		unsigned long duration = pulseIn(_Echo, HIGH);
		float distanceCm = (duration * cSound) / 20000;
		return distanceCm;
	}
}

float Ping::Poll(int iterations, int pauseTime) {
	float distance;
	for(int i = 0; i < iterations; i++) {
		distance += Sample();
		delay(pauseTime);
	}
	distance /= iterations;
	return distance;
}

float Ping::toInches(float convert) {
	return convert * .39370;
}