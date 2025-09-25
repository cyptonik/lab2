#include "bisection.h"
#include <iostream>
#include <cmath>

double bisect(double (*func)(double), double a, double b){
    if (a >= b) {
        return 0.0;
    }
    
    double fa = func(a);
    double fb = func(b);
    
    if (fa * fb > 0) {
        std::cout << "Error: Function must have opposite signs at a and b" << std::endl;
        return 0.0;
    }
    
    double c;
    int iteration = 0;
    
    while ((b - a) >= EPS) {
        iteration++;
        
        c = (a + b) / 2.0;
        double fc = func(c);
        
        if (fc == 0.0 || std::abs(fc) < EPS) {
            break;
        }
        
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        
    }
    
    return c;
}
