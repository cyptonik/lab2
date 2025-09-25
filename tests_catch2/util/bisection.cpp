#include "bisection.h"

double bisect(double (*func)(double), double a, double b) 
{
	double c = a;
	while ((b-a) >= EPS)
	{
		c = (a+b)/2.0;

		if (func(c) == 0.0) {
			break;
		}

		if (func(c)*func(a) < 0) {	
			a = c;
		}	
		else {
			b = c;
		}
	}

	return c;
}
