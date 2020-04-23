
#include "vect.h"
#include "matrix.h"
#include "hmath.h"


int main()
{

    vector<vector<double>>x1;
    vector<vector<double>>x2;
    vector<double>y;
    y.push_back(8);
    y.push_back(-3);
    y.push_back(2);
    x1.push_back(y);
    y.clear();
    y.push_back(5);
    y.push_back(6);
    y.push_back(2);
    x1.push_back(y);
    y.clear();
    y.push_back(5);
    y.push_back(8);
    y.push_back(4);
    x1.push_back(y);
    y.clear();
    y.push_back(1);
    y.push_back(-2);
    y.push_back(3);
    x1.push_back(y);

    y.clear();
    y.push_back(7);
    y.push_back(-3);
    y.push_back(2);
    x2.push_back(y);
    y.clear();
    y.push_back(5);
    y.push_back(6);
    y.push_back(2);
    x2.push_back(y);
    y.clear();
    y.push_back(5);
    y.push_back(8);
    y.push_back(4);
    x2.push_back(y);
    y.clear();
    y.push_back(1);
    y.push_back(-2);
    y.push_back(3);
    x2.push_back(y);
    matrix::printMatrix(matrix::drehMatrirx(0,XAxis));

    return 0;
}
