#pragma once


class Fraction
{
	int numerator;
	int deniminator;

public:
	Fraction()
	{
		numerator = 0;
		deniminator = 1;
	}

	Fraction sum(Fraction f)
	{
		Fraction res;
		res.deniminator = 1;
		res.numerator = 1;

		return res;
	}
};