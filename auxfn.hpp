//
//  auxfn.hpp
//  euler2
//
//  Created by Joo Seung Lee on 6/16/16.
//  Copyright © 2016 Joo Seung Lee. All rights reserved.
//

#ifndef auxfn_hpp
#define auxfn_hpp

#include <string>
#include <iostream>

using namespace std;

class matrix
{
private:
    // just change the number here to change matrix size
    int size = 20;
    int ar[20][20];
public:
    matrix();
    void setmatrix(int row, int col, int k);
    void parsematrix(string s);
    void printmatrix();
    long maxverticalproduct();
    long maxhorizontalproduct();
    long maxdiagonalproduct();

};




#endif /* auxfn_hpp */
