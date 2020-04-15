#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printMatrix(vector<vector<double>> mat){
    cout<<mat.size()<<" x "<<mat.size()<<"Matrix:\n";
    for (unsigned long long i=0;i<mat.size();++i) {
        cout<<"|";
         for (unsigned long long j=0;j<mat[0].size();++j) {
                cout<<mat[i][j]<<"\t";
            }
        cout<<"|\n";
    }
}
void printMatrix(vector<double> mat){
    vector<vector<double>> mat_1;
    mat_1.push_back(mat);
    printMatrix(mat_1);
}

vector<vector<double>> matrixMultiplikation(vector<vector<double>> v1, vector<vector<double>> v2){
    vector<vector<double>> res;
    cout<<"v1 ="<< v1.size()<<" x "<<v1[0].size()<<"\n";
    cout<<"v2 ="<< v2.size()<<" x "<<v2[0].size()<<"\n";
    if( v1[0].size()==v2.size()){
        cout<<" v1 x= v2 y = "<<v1.size()<<"\n";
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

vector<vector<double>> matrixMultiplikation(vector<vector<double>> v1, vector<double> v2){
    vector<vector<double>> v2_1;
    v2_1.push_back(v2);
    return matrixMultiplikation(v1,v2_1);
}

vector<vector<double>> matrixMultiplikation(vector<double> v1, vector<vector<double>> v2){
    vector<vector<double>> v1_1;
    v1_1.push_back(v1);
    return matrixMultiplikation(v1_1,v2);
}

vector<vector<double>> matrixMultiplikation(vector<double> v1, vector<double> v2){
    vector<vector<double>> v1_1;
    v1_1.push_back(v1);
    vector<vector<double>> v2_1;
    v2_1.push_back(v2);
    return matrixMultiplikation(v1_1,v2_1);
}

vector<vector<double>> matrixMultiplikation(double multi,vector<vector<double>> v1){
    for (unsigned long long i=0;i<v1.size();++i) {
        for (unsigned long long j=0;j<v1[0].size();++j) {
             v1[i][j]=v1[i][j]*multi;
        }

    }
    return v1;
}
vector<double> matrixMultiplikation(double multi,vector<double> v1){
        for (unsigned long long j=0;j<v1.size();++j) {
             v1[j]=v1[j]*multi;
        }
    return v1;
}
vector<double> getSpalte(vector<vector<double>> mat,unsigned long long spalte){
    vector<double> res;
    for(unsigned long long i=0;i<mat.size();++i){
        if(spalte<mat[0].size()){
            res.push_back(mat[i][spalte]);
        }
    }
    return res;
}

vector<double> matrixAddition(vector<double> v1, vector<double> v2){
    vector<double> res;
    if(v1.size()==v2.size()){
        for (unsigned long long i=0;i<v1.size();++i) {
            res.push_back(v1[i]+v2[i]);
        }
    }
    return res;
}
vector<vector<double>> matrixAddition(vector<vector<double>> v1, vector<vector<double>> v2){
    vector<vector<double>> res;
    if(v1.size()==v2.size()){

        for (unsigned long long i=0;i<v1.size();++i) {
            res.push_back(matrixAddition(v2[i],v1[i]));
        }
    }
    return res;
}

vector<double> matrixSubtraktion(vector<double> v1, vector<double> v2){
    vector<double> res;

    if(v1.size()==v2.size()){
        for (unsigned long long i=0;i<v1.size();++i) {
            res.push_back(v1[i]-v2[i]);
        }
    }
    return res;
}

vector<vector<double>> matrixSubtraktion(vector<vector<double>> v1, vector<vector<double>> v2){
    vector<vector<double>> res;
    if(v1.size()==v2.size()){

        for (unsigned long long i=0;i<v1.size();++i) {
            res.push_back(matrixSubtraktion(v1[i],v2[i]));
        }
    }
    return res;
}

vector<vector<double>> matrixTransponieren(vector<vector<double>> v1){
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
#endif // MATRIX_H
