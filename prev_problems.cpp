//
//  prev_problems.cpp
//  euler2
//
//  Created by Joo Seung Lee on 6/16/16.
//  Copyright © 2016 Joo Seung Lee. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "string_arithmetic.hpp"
#include "auxfn.hpp"

using namespace std;

bool is_palindrome(int n){
    string how = to_string(n);
    bool result = true;
    for(int i = 0; i < ceil(how.length()); i++){
        if(how[i] != how[how.length()-i-1]){
            result = false;
            break;
        }
    }
    return result;
}

bool is_prime(int pr[], int size, int x){
    int maxindex;
    for(maxindex = 0; maxindex < size; maxindex++){
        if(pr[maxindex] * pr[maxindex] > x)
            break;
    }
    for(int i = 0; i < maxindex; i++){
        if(x%pr[i] == 0)
            return false;
    }
    return true;
}

void problem_9(){
    // simple algebra
}

void problem_11(){
    matrix a;
    ifstream in_file;
    in_file.open("input.txt");
    if(in_file.fail()){
        cout << "input.txt" << endl;
        exit(0);
    }
    string line;
    getline(in_file, line);
    a.parsematrix(line);
    
    cout << "maximum product is: " << max(a.maxverticalproduct(), a.maxdiagonalproduct(), a.maxhorizontalproduct()) << endl;
    
}

void problem_12(int how_many_factors_do_you_want){
    int hope = 1;
    int adder = 2;
    int contingency = 0;
    int maxcount = 0;

    while(maxcount < how_many_factors_do_you_want-1){
        // reset count
        int count = 0;
        for(int i = 1; i <= sqrt(hope); i++){
            if(hope % i == 0){
                count++;
            }
        }
        // scale count
        count *= 2;
        if((int)sqrt(hope) * (int)sqrt(hope) == hope){
            count -= 1;
        }
        // prep for next loop
        contingency = hope;
        hope = hope + adder;
        adder++;
 
        // update maxcount
        if(count > maxcount){
            maxcount = count;
        }
    }
    cout << "number of factors: " << maxcount << endl;
    cout << "the number is: " << contingency << endl;
}

string problem_13(string om){
    string sum[100];
    int count = 0;
    int reset = 0;
    
    for(int i = 0; i < 5000; i++){
        sum[count] += om[i];
        reset++;
        if(reset == 50){
            count++;
            reset = 0;
        }
    }
    string result = "0";
    for(int i = 0; i < 100; i++){
        result = string_adder(result, sum[i]);
    }
    return result;
}


void problem_14(){
    long maxstarter = 13;
    long maxcount = 10;
    
    for(int i = 14; i < 1000000; i++){
        long j = i;
        long count = 0;
        while(j != 1){
            if(j % 2 == 0){
                j = j /2;
                count++;
            }
            else{
                j = 3*j + 1;
                count++;
            }
        }
        count++;
        if(count > maxcount){
            maxcount = count;
            maxstarter = i;
        }
    }
 
    cout << "maxstarter is: " << maxstarter << endl;
    cout << "maxcount is: " << maxcount << endl;
}

void problem_15(){
    //return 40!/(20! * 20!);
}

void problem_16(){
    string horolo = "2";
    for(int i = 0; i < 999; i ++){
        horolo = string_adder(horolo, horolo);
    }
    int s;
    cout << horolo << endl;
    for(int i = 0; i < horolo.length(); i++){
        s += horolo[i] - '0';
    }
    cout << s << endl;
}


void problem_17(){
    // sum of letters from one to one thousand
    int digit[9] = {3,3,5,4,4,3,5,5,4};
    int hundred = 7;
    int tens[9] = {3,6,6,5,5,5,7,6,6};
    int teens[9] = {6,6,8,8,7,7,9,8,8};
 
    int one_to_nine;
    for(int i = 0; i < 9; i++)
        one_to_nine += digit[i];
    
    int ten_to_nineteen;
    for(int i = 0; i < 9; i++)
        ten_to_nineteen += teens[i];
    ten_to_nineteen += 3;
    
    int twenty_to_ninety_nine = 0;
    twenty_to_ninety_nine += 8 * one_to_nine;
    for(int i = 1; i < 9; i++)
        twenty_to_ninety_nine += 10 * tens[i];
 
    int one_to_ninety_nine = one_to_nine + ten_to_nineteen + twenty_to_ninety_nine;
    cout << "1 to 99: " << one_to_ninety_nine << endl;
 
    int result;
    result = 10 * one_to_ninety_nine;      // last two digits for 1-999
    result += (hundred * 9);               // we have 9 instances where a number ends with two 0's
    result += ((hundred + 3) * 99 * 9);    // we have 99 * 9 instances where last two digits != 00
    result += one_to_nine * 100;           // prefix for hundred
    result += 11;                          // one hundred
    cout << "1 to 1000: " << result << endl;
}
