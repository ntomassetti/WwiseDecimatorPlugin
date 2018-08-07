#include "DecimatorFXDSP.h"



DecimatorFXDSP::DecimatorFXDSP() : _bits (32), _rate(1.0f)
{
}


DecimatorFXDSP::~DecimatorFXDSP()
{
}

float DecimatorFXDSP::process(float input)
{
	m = 1 << (_bits - 1);
	cnt += _rate;
	if (cnt >= 1)
	{
		cnt -= 1;
		y = (long int)(input*m) / (float)m;
	}
	return y;
}

void DecimatorFXDSP::updateParameters(int bits, float rate)
{
	_bits = bits;
	_rate = rate;
	//Wwise will go beyond what the decimator expects. Force it to not do that...
	if (_bits <= 0) {
		_bits = 1;
	}else if(_bits >= 24){
		_bits = 24;
	}

	if (_rate <= 0) {
		_rate = 0.01f;
	}else if(_rate >= 1.0f){
		_rate = 1.0f;
	}
}
