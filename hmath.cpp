#include "hmath.h"
#include <math.h>

hmath::hmath()
{

}
double hmath::sinGrad(double arg_winkel){
    return sin(gradInRad(arg_winkel));
}
double hmath::cosGrad(double arg_winkel){
    return cos(gradInRad(arg_winkel));
}
double hmath::tanGrad(double arg_winkel){
    return tan(gradInRad(arg_winkel));
}
    double hmath::gradInRad(double arg_grad){
    return arg_grad/180*PI;
}
    double hmath::radInGrad(double arg_rad){
    return arg_rad/PI*180;
}
