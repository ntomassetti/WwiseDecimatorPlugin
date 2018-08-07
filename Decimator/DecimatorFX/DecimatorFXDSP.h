#pragma once
class DecimatorFXDSP
{
public:
	DecimatorFXDSP();
	~DecimatorFXDSP();

	float process(float input);
	void updateParameters(int bits, float rate);

private:
	int _bits;
	float _rate;
	long int m;// = 1 << (_bits - 1);
	float y = 0, cnt = 0;
};

