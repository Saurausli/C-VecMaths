#include "vect.h"
#include <iostream>
using namespace std;

vect::vect(){

}
void vect::printRitchtungsVektor(richtungsVektor v){
    cout<<"vect{"<<v.x<<", "<<v.y<<", "<<v.z<<"}";
}

void vect::printlnRitchtungsVektor(richtungsVektor v){
   printRitchtungsVektor(v);
   cout<<"\n";
}

void vect::printPunkt(punkt pt){
    cout<<"pt["<<pt.x<<", "<<pt.y<<", "<<pt.z<<"]";
}

void vect::printlnPunkt(punkt pt){
   printPunkt(pt);
   cout<<"\n";
}

void vect::printStrecke(strecke s){
    cout<<"st.(";
    printRitchtungsVektor(s.start);
    cout<<" + x * ";
    printRitchtungsVektor(s.strecke);
}

void vect::printlnStrecke(strecke s){
    printStrecke(s);
    cout<<"\n";
}

string vect::vorzeichen(double x){
    if(x<0){
        return to_string(x);
    }
    else{
        return " + "+ to_string(x);
    }
}

void vect::printEbenenGleichung(ebenenGleichung eb){
    cout<<"eb(0 = "<<eb.a<<"* x "<<vorzeichen(eb.b)<<" * y "<<vorzeichen(eb.c)<<" * z "<<vorzeichen(eb.d)<<")";
}

void vect::printlnEbenenGleichung(ebenenGleichung eb){
    printEbenenGleichung(eb);
    cout<<"\n";
}

punkt vect::getPunkt(double x,double y,double z){
    punkt pt;
    pt.x=x;
    pt.y=y;
    pt.z=z;
    return pt;
}

richtungsVektor vect::getVektor(double x,double y,double z){
    richtungsVektor vec;
    vec.x=x;
    vec.y=y;
    vec.z=z;
    return vec;
}

richtungsVektor vect::getVektor(punkt start,punkt ende){
    struct richtungsVektor v;
    v.x=ende.x-start.x;
    v.y=ende.y-start.y;
    v.z=ende.z-start.z;
    return v;
}

richtungsVektor vect::getVektor(punkt start){
    struct richtungsVektor v;
    v.x=start.x;
    v.y=start.y;
    v.z=start.z;
    return v;
}

richtungsVektor vect::getKreuzprodukt(richtungsVektor vec1,richtungsVektor vec2){
    struct richtungsVektor vec;
    vec.x=(vec1.y*vec2.z)-(vec1.z*vec2.y);
    vec.y=(vec1.z*vec2.x)-(vec1.x*vec2.z);
    vec.z=(vec1.x*vec2.y)-(vec1.y*vec2.x);
    return vec;
}

double vect::skalarProdukt(richtungsVektor vec1,richtungsVektor vec2){
    double prod;
    prod=vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z;
    return prod;
}

double vect::minusSkalarProdukt(richtungsVektor vec1,richtungsVektor vec2){
    double prod;
    prod=vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z;
    return prod;
}

strecke vect::getStrecke(richtungsVektor start, richtungsVektor richtung){
     strecke s;
     s.start=start;
     s.strecke=richtung;
     return s;
}

strecke vect::getStrecke(punkt start, richtungsVektor richtung){
    return getStrecke(getVektor(start),richtung);
}

punkt vect::getPunkt(richtungsVektor vec){
    punkt pt;
    pt.x=vec.x;
    pt.y=vec.y;
    pt.z=vec.z;
    return pt;
}

ebenenGleichung vect::getEbenenGleichung(double a, double b, double c, double d){
    ebenenGleichung eb;
    eb.a=a;
    eb.b=b;
    eb.c=c;
    eb.d=d;
    return eb;
}

ebenenGleichung vect::normalVektor(richtungsVektor norm, punkt pt){
    ebenenGleichung eb;
    eb.a=norm.x;
    eb.b=norm.y;
    eb.c=norm.z;
    eb.d=-norm.x*pt.x-norm.y*pt.y-norm.z*pt.z;
    return eb;
}

ebenenGleichung vect::getEbenenGleichung(punkt pt1, punkt pt2, punkt pt3){
    return normalVektor(getKreuzprodukt(getVektor(pt1,pt3),getVektor(pt1,pt2)),pt1);
}

double vect::getX(ebenenGleichung eb, double y, double z){
    return (eb.b*y+eb.c*z+eb.d)/-eb.a;
}

double vect::getY(ebenenGleichung eb, double x, double z){
    return (eb.a*x+eb.c*z+eb.d)/-eb.b;
}

double vect::getZ(ebenenGleichung eb, double x, double y){
    return (eb.a*x+eb.b*y+eb.d)/-eb.c;
}

bool vect::parallelitaet(ebenenGleichung eb, strecke st){
    double sk;
    sk=skalarProdukt(getVektor(eb.a,eb.b,eb.c),st.strecke);
    if(sk<0||sk>0){
        return true;
    }
    else {
        return false;
    }
}

bool vect::aufliegend(ebenenGleichung eb, punkt pt){
    cout<<eb.a*pt.x<<" + "<<eb.b*pt.y<<" + "<<eb.c*pt.z<<" + "<<eb.d<< " =";
    cout<<eb.a*pt.x+eb.b*pt.y+eb.c*pt.z+eb.d<<"\n";
    if(eb.a*pt.x+eb.b*pt.y+eb.c*pt.z+eb.d==0.0){
        cout<<" true";
        return true;
    }
    else{
        cout<<"false";
        return false;
    }
}

bool vect::aufliegend(ebenenGleichung eb, strecke st){
    if(parallelitaet(eb,st)&&aufliegend(eb,getPunkt(st.start))){
         return true;
    }
    return false;
    }
