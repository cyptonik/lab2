#include <iostream>
#include <cmath>

#ifndef BISECT_H
#define BISECT_H
#define EPS 1e-4

double bisect(double (*func)(double), double a, double b);

#endif
