//
//  auxfn.cpp
//  euler2
//
//  Created by Joo Seung Lee on 6/16/16.
//  Copyright © 2016 Joo Seung Lee. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include "auxfn.hpp"

using namespace std;

matrix::matrix(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            ar[i][j] = 0;
        }
    }
}

//setvalue
void matrix::setmatrix(int row, int col, int k){
    ar[row][col] = k;
}

//fill in matrix
void matrix::parsematrix(string s){
    string clear = "";
    int rowcount = 0;
    int columncount = 0;
    
    for(int i = 0; i < s.length(); i++){
        if(columncount == size){
            rowcount++;
            columncount = 0;
        }
        if(s[i] == ' '){
            int a = stoi(clear);
            setmatrix(rowcount, columncount, a);
            columncount++;
            clear = "";
        }
        else{
            clear += s[i];
        }
    }
}

//display matrix
void matrix::printmatrix(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}

long matrix::maxverticalproduct(){
    long product = 0;
    for(int col = 0; col < size; col++){
        for(int row = 0; row < size-3; row++){
            long how = ar[row][col] * ar[row+1][col] * ar[row+2][col] * ar[row+3][col];
            if(how > product){
                product = how;
            }
        }
    }
    return product;
}

long matrix::maxhorizontalproduct(){
    long product = 0;
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size-3; col++){
            long how = ar[row][col] * ar[row][col+2] * ar[row][col+1] * ar[row][col+3];
            if(how > product){
                product = how;
            }
        }
    }
    return product;
}

long matrix::maxdiagonalproduct(){
    long product = 0;
    int a,b,c,d;
    for(int row = 0; row < size-3; row++){
        for(int col = 0; col < size-3; col++){
            long how = ar[row][col] * ar[row+1][col+1] * ar[row+2][col+2] * ar[row+3][col+3];
            if(how > product){
                product = how;
            }
        }
    }
    for(int col = 3; col < size; col++){
        for(int row = 0; row < size-3; row++){
            long how = ar[row][col] * ar[row+1][col-1] * ar[row+2][col-2] * ar[row+3][col-3];
            if(how > product){
                a =ar[row][col]; b =ar[row+1][col-1]; c=ar[row+2][col-2]; d=ar[row+3][col-3];
                product = how;
            }
        }
    }
    return product;
}