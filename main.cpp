
#include "vect.h"
#include "matrix.h"
#include "hmath.h"


int main()
{
    denaHartSatz satz;
    satz.alpha=0;
    satz.d=0;
    satz.r=0;

    richtungsVektor richt;
    richt.x=1;
    richt.y=0;
    richt.z=0;
    richtungsVektor res;
    vector<vector<double>> hom;

    for(int i=0;i<=360;++i){
        satz.winkel=i;
    hom=matrix::denavitHartenbergTransformation(satz);
    res =matrix::getPunkt(hom,richt);
    cout<<i<<";"<<res.x<<";"<<res.y<<"\n";
    }

    //matrix::printMatrix(matrix::matrixMultiplikation(matrix::drehMatrirx(90,XAxis),matrix::drehMatrirx(270,XAxis)));
    return 0;
}
