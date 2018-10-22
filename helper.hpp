//
//  helper.hpp
//  euler2
//
//  Created by Joo Seung Lee on 6/19/16.
//  Copyright © 2016 Joo Seung Lee. All rights reserved.
//

#ifndef string_arithmetic_hpp
#define string_arithmetic_hpp

#include <string>
#include "graph.hpp"
using namespace std;

struct person{
    string name;
    int value;
};
bool is_palindrome(int n);
bool is_prime(int* pr, int size, int x);
string remove_zeroes(string str);
string string_adder(string string1, string string2);
string string_multiplier(string string1, string string2);
string string_division(string s1, string s2);
int string_repeating_decimals(string s1);
string string_subtractor1(string string1, string string2);
string string_subtractor2(string string1, string string2);
string string_decrement(string string1);
int fibonacci(string s1, string s2, int index);
string factorial(string string1);
int factorial(int number);
void parse_string_to_array(int numbers[], string string1, int size);
void depth_first_addition(int* max, node* root, int partial_sum);
int get_factors(int number);
bool is_amicable(int number);
int parse_string_to_names(person people[], string string1);
void alphabetical_insertion_sort(person names[], int size);
bool compare_names(string name1, string name2);
void insert(person names[], int position, person value);
bool number_exists_in_array(int array[], int key, int size);
#endif /* helper_hpp */
