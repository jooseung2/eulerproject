//
//  main.cpp
//  euler2
//
//  Created by Joo Seung Lee on 6/16/16.
//  Copyright © 2016 Joo Seung Lee. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "auxfn.hpp"
#include "prev_problems.h"
#include "string_arithmetic.hpp"

using namespace std;

int main() {
    /*
    ifstream in_file;
    in_file.open("input.txt");
    if(in_file.fail()){
        cout << "input.txt" << endl;
        exit(0);
    }
    string line;
    getline(in_file, line);
    */
    cout << string_subtractor("5", "4") << endl;
    
    return 0;
}
