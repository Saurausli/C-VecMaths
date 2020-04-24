#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <string>
#include "vect.h"

using namespace std;

#define XAxis 1
#define YAxis 2
#define ZAxis 3


struct denaHartSatz{
    double winkel;
    double alpha;
    double r;
    double d;
};

class matrix{
public:
    matrix();
    static void printMatrix(vector<vector<double>> mat);
    static void printMatrix(vector<double> mat);
    static vector<vector<double>> matrixMultiplikation(vector<vector<double>> v1, vector<vector<double>> v2);
    static vector<vector<double>> matrixMultiplikation(vector<vector<double>> v1, vector<double> v2);
    static vector<vector<double>> matrixMultiplikation(vector<vector<double>> v1, richtungsVektor v2);
    static vector<vector<double>> matrixMultiplikation(vector<double> v1, vector<vector<double>> v2);
    static vector<vector<double>> matrixMultiplikation(vector<double> v1, vector<double> v2);
    static vector<vector<double>> matrixMultiplikation(double multi,vector<vector<double>> v1);
    static vector<double> matrixMultiplikation(double multi,vector<double> v1);
    static vector<double> getSpalte(vector<vector<double>> mat,unsigned long long spalte);
    static vector<double> matrixAddition(vector<double> v1, vector<double> v2);
    static vector<vector<double>> matrixAddition(vector<vector<double>> v1, vector<vector<double>> v2);
    static vector<double> matrixSubtraktion(vector<double> v1, vector<double> v2);
    static vector<vector<double>> matrixSubtraktion(vector<vector<double>> v1, vector<vector<double>> v2);
    static vector<vector<double>> matrixTransponieren(vector<vector<double>> v1);
    static vector<vector<double>> drehMatrix(double arg_Winkel);
    static vector<vector<double>> drehMatrix(double arg_Winkel, unsigned int arg_Achse);
    static richtungsVektor verschiebungsVektor(double arg_Grundvektor, double arg_ZHoehe, double arg_Winkel);
    static vector<vector<double>> homogeneTransformationsMatrix(vector<vector<double>> arg_drehMatrix, vector<vector<double>> arg_grundDrehMatrix, richtungsVektor arg_verschiebungsVektor);
    static richtungsVektor getPunkt(vector<vector<double>> arg_h,richtungsVektor v2);
    static vector<vector<double>> denavitHartenbergTransformation(denaHartSatz arg_satz);
    static bool drehMatrixUeberpruefen(vector<vector<double>> vec);
    static vector<vector<double>> denavitHartenbergTransformation(double arg_winkel, double arg_alpha, double arg_r, double arg_d);
    static denaHartSatz denavitHartenberg(double arg_winkel, double arg_alpha, double arg_r, double arg_d);
};
#endif // MATRIX_H
