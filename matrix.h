#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define XAxis 1
#define YAxis 2
#define ZAxis 3
class matrix{
public:
    matrix();
    static void printMatrix(vector<vector<double>> mat);
    static void printMatrix(vector<double> mat);
    static vector<vector<double>> matrixMultiplikation(vector<vector<double>> v1, vector<vector<double>> v2);
    static vector<vector<double>> matrixMultiplikation(vector<vector<double>> v1, vector<double> v2);
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
    static vector<vector<double>> drehMatrirx(double arg_Winkel, unsigned int arg_Achse);
};
#endif // MATRIX_H
