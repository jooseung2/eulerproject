//
//  helper.cpp
//  euler2
//
//  Created by Joo Seung Lee on 6/19/16.
//  Copyright © 2016 Joo Seung Lee. All rights reserved.
//

#include "helper.hpp"
#include "graph.hpp"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>

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

string remove_zeroes(string str)
{
    int count = 0;
    string result = "";
    while(str[count] == '0'){
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
    
    // cannot add negative number
    
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

string string_subtractor1(string string1, string string2){
    return to_string(stoi(string1)-stoi(string2));
}

string string_division(string s1, string s2){
    int dividend = stoi(s1);
    int divisor = stoi(s2);
    bool has_no_decimal_point = true;
    string result = "";
    int count = 0;
    
    do{
        if(dividend < divisor){
            result = result + to_string(dividend / divisor);
            
            if(has_no_decimal_point){
                result = result + ".";
                has_no_decimal_point = false;
                dividend = 10 * dividend;
                continue;   // don't need a zero if we add a decimal point
            }
            
            dividend = 10 * dividend;
        }
        else{
            result = result + to_string(dividend / divisor);
            dividend = dividend % divisor;
        }
        
        if(!has_no_decimal_point)
            count++;
        if(count % 5 == 0){
            if(string_repeating_decimals(result))
                dividend = 0;
        }
    } while(dividend != 0);
    
    return result;
}

int string_repeating_decimals(string s1){
    int count = 0;
    return count;
}

string string_subtractor2(string string1, string string2){
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

string string_decrement(string string1){
    string result = string1;
    long length = string1.length();
    if(result[length-1] != '0'){
        result[length-1] -= 1;
        return result;
    }
    else{
        int num_of_zeroes = 0;
        for(long i = length; i > 0; i--){
            if(result[i-1] == '0')
                num_of_zeroes++;
            else
                break;
        }
        long i; long j = 0;
        for(i = 0; i < num_of_zeroes; i++){
            result[length-i-1] = '9';
            j++;
            
        }
        result[length-j-1] -= 1;
        return result;
    }
}

int fibonacci(string s1, string s2, int index){
    if(s2.length() == 1000)
        return index;
    string temp = string_adder(s1, s2);
    return fibonacci(s2, temp, index+1);
}

string string_factorial(string string1){
    if(string1 == "1")
        return "1";
    else
        return string_multiplier(string1, string_decrement(string1));
    /*
    int number = stoi(string1);
    for(int i = 0; i < number; i++){
        result = string_multiplier(result, string1);
        string1 = string_decrement(string1);
    }
    return result;
     */
}

int factorial(int number){
    if(number < 1){
        return -1;
    }
    else if(number == 1){
        return 1;
    }
    else
        return number * factorial(number - 1);
}

void parse_string_to_array(int numbers[], string string1, int size){
    // parse a string into an array of double digit ints
    string temp_str = "";
    int n_of_n_so_far = 0;
    int i = 0;
    
    while(n_of_n_so_far != size){
        if(temp_str.length() == 2){
            numbers[n_of_n_so_far] = stoi(temp_str);
            temp_str = "";
            n_of_n_so_far++;
        }
        if(string1[i] != ' '){
            temp_str = temp_str + string1[i];
        }
        i++;
    }
}

void depth_first_addition(int* max, node* root, int partial_sum){
    partial_sum += root->val_is();
    if(root->rightchild != NULL && root->leftchild != NULL){
        depth_first_addition(max, root->leftchild, partial_sum);
        depth_first_addition(max, root->rightchild, partial_sum);
    }
    else{
        if(partial_sum > *max)
            *max = partial_sum;
    }
    /*
    depth first search algorithm.
    updates the partial sum every time the search algorithm moves on to a child node.
    stops when the algorithm reaches the bottom, and compares the partial sum with the max variable and updates it if the partial sum is greater.
    */
}

int get_factors(int number){
    // factors of n less than n. e.g. f(12) = {1,2,3,4,6};
    
    int sqrt_n = sqrt(number);
    int sum = 0;
    for(int i = 2; i <= sqrt_n; i++){
        if(number % i == 0){
            sum += i;
            if(i != number / i){
                sum += number / i;
            }
        }
    }
    sum++;
    return sum;
}

bool is_amicable(int number){
    bool result = false;
    
    int sum = get_factors(number);
    int other_sum = get_factors(sum);
    
    if(other_sum == number && number != sum)
        result = true;
    return result;
}

int parse_string_to_names(person people[], string string1){
    int count = 0;
    //bool inside = false;
    string temp = "";
    int tempval = 0;
    
    for(int i = 0; i < string1.length(); i++){
        if(string1[i] == 44){ // ascii value of comma is 44, of double quote 34
            people[count].name = temp;
            people[count].value = tempval;
            temp = "";
            tempval = 0;
            count++;
        }
        else if(string1[i] >= 65 && string1[i] <= 90){ // A to Z
            temp = temp + string1[i];
            tempval += string1[i] - 'A' + 1;
        }
    }
    if(temp != ""){
        people[count].name = temp;
        people[count].value = tempval;
        count++;
    }
    
    return count;
}

// alphabetical_insertion_sort and insert are from EECS 214

void alphabetical_insertion_sort(person names[], int size){
    for(int i = 1; i < size; i++){
        insert(names, i, names[i]);
    }
}

bool compare_names(string name1, string name2){
    long right_length;
    bool result = false;
    string temp = "";
    right_length = (name1.length() >= name2.length()) ? name2.length() : name1.length();
    
    for(int i = 0; i < right_length; i++){
        if(name1[i] > name2[i]){
            result = true;
        }
        else if(name1[i] == name2[i]){
            temp = temp + name1[i];
        }
        else if(name1[i] < name2[i]){
            break;
        }
    }
    if((temp == name1 || temp == name2) && name1.length() > name2.length()){
        result = true;
    }
    
    // true if switch needed
    return result;
}

void insert(person names[], int position, person value){
    int i;
    for(i = position - 1; i >= 0 && compare_names(names[i].name, value.name); i--)
        names[i+1] = names[i];
    names[i+1] = value;
}

int sum_of_factors(int n){
    return n;
}

bool number_exists_in_array(int array[], int key, int size){
    for(int i = 0; i < size; i++){
        if(array[i] == key){
            return true;
        }
    }
    return false;
}
