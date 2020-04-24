#include "matrix.h"
#include <iostream>
#include <cmath>
#include "hmath.h"
using namespace std;
matrix::matrix(){

}
void matrix::printMatrix(vector<vector<double>> mat){
    cout<<mat.size()<<" x "<<mat[0].size()<<"Matrix:\n";
    for (unsigned long long i=0;i<mat.size();++i) {
        cout<<"|";
         for (unsigned long long j=0;j<mat[0].size();++j) {
             if(mat[i][j]>=0){
                 cout<<" ";
             }
            cout<<round(mat[i][j]*1000)/1000;
             if(j<mat[0].size()-1){
                cout<<"\t";
             }
            }
        cout<<"|\n";
    }
}
void matrix::printMatrix(vector<double> mat){
    vector<vector<double>> mat_1;
    mat_1.push_back(mat);
    printMatrix(mat_1);
}

vector<vector<double>> matrix::matrixMultiplikation(vector<vector<double>> v1, vector<vector<double>> v2){
    vector<vector<double>> res;
    if( v1[0].size()==v2.size()){
        for (unsigned long long i=0;i<v1.size();++i) {
            vector<double> preRes;

            for (unsigned long long j=0;j<v2[0].size();++j) {

                        double value=0;
                        for (unsigned long long k=0; k<v1[0].size();++k) {
                            value=v1[i][k]*v2[k][j]+value;
                        }
                        preRes.push_back(value);
                }
                res.push_back(preRes);
                preRes.clear();
          }


    }
    return res;
}

vector<vector<double>> matrix::matrixMultiplikation(vector<vector<double>> v1, vector<double> v2){
    vector<vector<double>> v2_1;
    v2_1.push_back(v2);
    return matrixMultiplikation(v1,v2_1);
}

vector<vector<double>> matrix::matrixMultiplikation(vector<double> v1, vector<vector<double>> v2){
    vector<vector<double>> v1_1;
    v1_1.push_back(v1);
    return matrixMultiplikation(v1_1,v2);
}

vector<vector<double>> matrix::matrixMultiplikation(vector<double> v1, vector<double> v2){
    vector<vector<double>> v1_1;
    v1_1.push_back(v1);
    vector<vector<double>> v2_1;
    v2_1.push_back(v2);
    return matrixMultiplikation(v1_1,v2_1);
}

vector<vector<double>> matrix::matrixMultiplikation(double multi,vector<vector<double>> v1){
    for (unsigned long long i=0;i<v1.size();++i) {
        for (unsigned long long j=0;j<v1[0].size();++j) {
             v1[i][j]=v1[i][j]*multi;
        }

    }
    return v1;
}
vector<vector<double>>  matrix::matrixMultiplikation(vector<vector<double>> v1, richtungsVektor v2){
    vector<vector<double>> _v2;
    _v2={{v2.x},{v2.y},{v2.z}};
    return matrixMultiplikation(v1,_v2);
}
vector<double> matrix::matrixMultiplikation(double multi,vector<double> v1){
        for (unsigned long long j=0;j<v1.size();++j) {
             v1[j]=v1[j]*multi;
        }
    return v1;
}
vector<double> matrix::getSpalte(vector<vector<double>> mat,unsigned long long spalte){
    vector<double> res;
    for(unsigned long long i=0;i<mat.size();++i){
        if(spalte<mat[0].size()){
            res.push_back(mat[i][spalte]);
        }
    }
    return res;
}

vector<double> matrix::matrixAddition(vector<double> v1, vector<double> v2){
    vector<double> res;
    if(v1.size()==v2.size()){
        for (unsigned long long i=0;i<v1.size();++i) {
            res.push_back(v1[i]+v2[i]);
        }
    }
    return res;
}
vector<vector<double>> matrix::matrixAddition(vector<vector<double>> v1, vector<vector<double>> v2){
    vector<vector<double>> res;
    if(v1.size()==v2.size()){

        for (unsigned long long i=0;i<v1.size();++i) {
            res.push_back(matrixAddition(v2[i],v1[i]));
        }
    }
    return res;
}

vector<double> matrix::matrixSubtraktion(vector<double> v1, vector<double> v2){
    vector<double> res;

    if(v1.size()==v2.size()){
        for (unsigned long long i=0;i<v1.size();++i) {
            res.push_back(v1[i]-v2[i]);
        }
    }
    return res;
}

vector<vector<double>> matrix::matrixSubtraktion(vector<vector<double>> v1, vector<vector<double>> v2){
    vector<vector<double>> res;
    if(v1.size()==v2.size()){

        for (unsigned long long i=0;i<v1.size();++i) {
            res.push_back(matrixSubtraktion(v1[i],v2[i]));
        }
    }
    return res;
}

vector<vector<double>> matrix::matrixTransponieren(vector<vector<double>> v1){
    vector<vector<double>> res;
    for (unsigned long long i=0;i<v1[0].size();++i) {
        vector<double> preRes;
        for (unsigned long long j=0;j<v1.size();++j) {
            preRes.push_back(v1[j][i]);
        }
        res.push_back(preRes);
        preRes.clear();
    }
    return res;
}
vector<vector<double>> matrix::drehMatrix(double arg_Winkel){
    return drehMatrix(arg_Winkel,ZAxis);
}
vector<vector<double>> matrix::drehMatrix(double arg_Winkel, unsigned int arg_Achse){

    vector<vector<double>> res;
    if(arg_Achse==XAxis){
        vector<double> vec;
        vec.push_back(1);
        vec.push_back(0);
        vec.push_back(0);
        res.push_back(vec);
        vec.clear();
        vec.push_back(0);
        vec.push_back(hmath::cosGrad(arg_Winkel));
        vec.push_back(-(hmath::sinGrad(arg_Winkel)));
        res.push_back(vec);
        vec.clear();
        vec.push_back(0);
        vec.push_back(hmath::sinGrad(arg_Winkel));
        vec.push_back(hmath::cosGrad(arg_Winkel));
        res.push_back(vec);
        vec.clear();
        return res;
    }
    if(arg_Achse==YAxis){
        vector<double> vec;
        vec.push_back(hmath::cosGrad(arg_Winkel));
        vec.push_back(0);
        vec.push_back(hmath::sinGrad(arg_Winkel));
        res.push_back(vec);
        vec.clear();
        vec.push_back(0);
        vec.push_back(1);
        vec.push_back(0);
        res.push_back(vec);
        vec.clear();
        vec.push_back(-(hmath::sinGrad(arg_Winkel)));
        vec.push_back(0);
        vec.push_back(hmath::cosGrad(arg_Winkel));
        res.push_back(vec);
        vec.clear();
        return res;
    }
    if(arg_Achse==ZAxis){
        vector<double> vec;
        vec.push_back(hmath::cosGrad(arg_Winkel));
        vec.push_back(-(hmath::sinGrad(arg_Winkel)));
        vec.push_back(0);
        res.push_back(vec);
        vec.clear();
        vec.push_back(hmath::sinGrad(arg_Winkel));
        vec.push_back(hmath::cosGrad(arg_Winkel));
        vec.push_back(0);
        res.push_back(vec);
        vec.clear();
        vec.push_back(0);
        vec.push_back(0);
        vec.push_back(1);
        res.push_back(vec);
        vec.clear();
        return res;
    }
    return res;
}

richtungsVektor matrix::verschiebungsVektor(double arg_RotationsLaenge,double arg_ZHoehe,double arg_Winkel){
    richtungsVektor verschiebungsVektor;
    verschiebungsVektor.x=arg_RotationsLaenge*hmath::cosGrad(arg_Winkel);
    verschiebungsVektor.y=arg_RotationsLaenge*hmath::cosGrad(arg_Winkel);
    verschiebungsVektor.z=arg_ZHoehe;
    return verschiebungsVektor;
}

vector<vector<double>> matrix::homogeneTransformationsMatrix(vector<vector<double>> arg_drehMatrix,vector<vector<double>> arg_grundDrehMatrix,richtungsVektor arg_verschiebungsVektor){
    vector<vector<double>> homogeneTransformationMatrix;
    if(drehMatrixUeberpruefen(arg_drehMatrix)&&drehMatrixUeberpruefen(arg_grundDrehMatrix)){
        homogeneTransformationMatrix=matrixMultiplikation(arg_drehMatrix,arg_grundDrehMatrix);
        homogeneTransformationMatrix[0].push_back(arg_verschiebungsVektor.x);
        homogeneTransformationMatrix[1].push_back(arg_verschiebungsVektor.y);
        homogeneTransformationMatrix[2].push_back(arg_verschiebungsVektor.z);
        vector<double> vec={0,0,0,1};
        homogeneTransformationMatrix.push_back(vec);
    }
    return homogeneTransformationMatrix;
}
richtungsVektor matrix::getPunkt(vector<vector<double>> arg_h,richtungsVektor v2){
    vector<vector<double>> P={{v2.x},{v2.y},{v2.z},{1}};
    vector<vector<double>> res;
    res=matrixMultiplikation(arg_h,P);
    v2.x=res[0][0];
    v2.y=res[1][0];
    v2.z=res[2][0];
    return v2;
}

bool matrix::drehMatrixUeberpruefen(vector<vector<double>> vec){
    if(vec.size()==3){
        if(vec[0].size()==3){
            if(vec[1].size()==3){
                if(vec[2].size()==3){
                    return true;
                }
            }
        }
    }
    return false;
}

denaHartSatz matrix::denavitHartenberg(double arg_winkel, double arg_alpha, double arg_r, double arg_d){
    denaHartSatz res;
    res.winkel=arg_winkel;
    res.alpha=arg_alpha;
    res.d=arg_d;
    res.r=arg_r;
    return  res;
}
vector<vector<double>> matrix::denavitHartenbergTransformation(double arg_winkel, double arg_alpha, double arg_r, double arg_d){
    return denavitHartenbergTransformation(denavitHartenberg(arg_winkel,arg_alpha,arg_r,arg_d));
}

vector<vector<double>> matrix::denavitHartenbergTransformation(denaHartSatz arg_satz){
    vector<vector<double>> res;
    res.push_back({hmath::cosGrad(arg_satz.winkel),(-hmath::sinGrad(arg_satz.winkel)*(hmath::cosGrad(arg_satz.alpha))),(hmath::sinGrad(arg_satz.winkel)*(hmath::sinGrad(arg_satz.alpha))),(arg_satz.r*(hmath::cosGrad(arg_satz.winkel)))});
    res.push_back({hmath::sinGrad(arg_satz.winkel),(hmath::cosGrad(arg_satz.winkel)*(hmath::cosGrad(arg_satz.alpha))),(-hmath::cosGrad(arg_satz.winkel)*(hmath::sinGrad(arg_satz.alpha))),(arg_satz.r*(hmath::sinGrad(arg_satz.winkel)))});
    res.push_back({0,hmath::sinGrad(arg_satz.winkel),hmath::cosGrad(arg_satz.alpha),arg_satz.d});
    res.push_back({0,0,0,1});
    return res;
}
