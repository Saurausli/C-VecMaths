#ifndef HMATH_H
#define HMATH_H

#define PI 3.14159265359

class hmath
{
public:
    hmath();
    static double sinGrad(double arg_winkel);
    static double cosGrad(double arg_winkel);
    static double tanGrad(double arg_winkel);
    static double gradInRad(double arg_grad);
    static double radInGrad(double arg_rad);
};

#endif // HMATH_H
