//
//  string_arithmetic.cpp
//  euler2
//
//  Created by Joo Seung Lee on 6/19/16.
//  Copyright © 2016 Joo Seung Lee. All rights reserved.
//

#include "string_arithmetic.hpp"
#include <stdio.h>
#include <iostream>
#include <string>

string remove_zeroes(string str)
{
    int howmanyzero;
    int count = 0;
    string result = "";
    while(str[count] == '0'){
        howmanyzero++;
        count++;
    }
    for(int i = count; i < str.length(); i++){
        result = result + str[i];
    }
    return result;
}

string string_adder(string string1, string string2){
    string result = "";
    bool carry = false;
    long s1 = string1.length(); long s2 = string2.length();
    
    // make string lengths equal so forloops wont crash
    if(s1 > s2)
        for(int i = 0; i < s1 - s2; i++)
            string2 = '0' + string2;
    else if(s1 < s2)
        for(int i = 0; i < s2 - s1; i++)
            string1 = '0' + string1;
    else{}
    
    for(int i = 0; i < string1.length(); i++){
        int a = string1[string1.length()-1-i] - '0';
        int b = string2[string2.length()-1-i] - '0';
        int d;
        d = (carry) ? a + b + 1 : a + b;
        string c;
        if (d >= 10){
            carry = true;
            c = to_string(d-10);
        }
        else{
            carry = false;
            c = to_string(d);
        }
        result = c + result;
    }
    
    if(carry)
        return "1" + result;
    else
        return result;
}

string string_subtractor(string string1, string string2){
    string result = "";
    bool anticarry = false;
    long s1 = string1.length(); long s2 = string2.length();
    
    if(s1 > s2)
        for(int i = 0; i < s1 - s2; i++)
            string2 = '0' + string2;
    else if(s1 < s2)
        for(int i = 0; i < s2 - s1; i++)
            string1 = '0' + string1;
    else{}
    
    s1 = string1.length(); s2 = string2.length();
    if(string1.length() != string2.length()){
        exit(1);
    }
    
    for(int i = 0; i < string1.length(); i++){
        char temp;
        char c1 = string1[s1-i-1]; char c2 = string2[s2-i-1];
        temp = (anticarry) ? c1 - c2 - 1 : c1 - c2;
        if(temp>=0)
            anticarry = false;
        else{
            temp = -temp;
            anticarry = true;
        }
        result = temp + result;
    }
    result = remove_zeroes(result);
    return result;
}

string string_multiplier(string string1, string string2){
    long temp2 = string2.length();
    string result = "0";
    
    for(int i = 0; i < temp2; i++){
        string temp3 = "0";
        int digit = string2[temp2-1-i] - '0';
        for(int j = 0; j < digit; j++)
            temp3 = string_adder(temp3, string1);
        for(int k = 0; k < i; k++)
            temp3 = temp3 + '0';
        result = string_adder(result, temp3);
    }
    
    return result;
}
