#ifndef VECT_H
#define VECT_H

#include <matrix.h>



struct richtungsVektor
{
  double x;
  double y;
  double z;
};

struct punkt{
    double x;
    double y;
    double z;
};

struct strecke{
    richtungsVektor start;
    richtungsVektor strecke;

};
struct ebenenGleichung{
    double a;
    double b;
    double c;
    double d;
};

class vect{
    public:
        vect();
        static void printRitchtungsVektor(richtungsVektor v);
        static void printlnRitchtungsVektor(richtungsVektor v);
        static void printPunkt(punkt pt);
        static void printlnPunkt(punkt pt);
        static void printStrecke(strecke s);
        static void printlnStrecke(strecke s);
        static string vorzeichen(double x);

        static void printEbenenGleichung(ebenenGleichung eb);
        static void printlnEbenenGleichung(ebenenGleichung eb);

        static punkt getPunkt(double x,double y,double z);
        static richtungsVektor getVektor(double x,double y,double z);
        static richtungsVektor getVektor(punkt start,punkt ende);
        static richtungsVektor getVektor(punkt start);
        static richtungsVektor getKreuzprodukt(richtungsVektor vec1,richtungsVektor vec2);
        static double skalarProdukt(richtungsVektor vec1,richtungsVektor vec2);
        static double minusSkalarProdukt(richtungsVektor vec1,richtungsVektor vec2);
        static strecke getStrecke(richtungsVektor start, richtungsVektor richtung);
        static strecke getStrecke(punkt start, richtungsVektor richtung);
        static punkt getPunkt(richtungsVektor vec);
        static ebenenGleichung getEbenenGleichung(double a, double b, double c, double d);
        static ebenenGleichung normalVektor(richtungsVektor norm, punkt pt);
        static ebenenGleichung getEbenenGleichung(punkt pt1, punkt pt2, punkt pt3);
        static double getX(ebenenGleichung eb, double y, double z);
        static double getY(ebenenGleichung eb, double x, double z);
        static double getZ(ebenenGleichung eb, double x, double y);
        static bool parallelitaet(ebenenGleichung eb, strecke st);
        static bool aufliegend(ebenenGleichung eb, punkt pt);
        static bool aufliegend(ebenenGleichung eb, strecke st);
};
#endif // VECT_H
