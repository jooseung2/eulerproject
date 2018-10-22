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
#include "matrix.hpp"
#include "helper.hpp"
#include "graph.hpp"

using namespace std;

void problem_1(){
    int sum = 0;
    for(int i = 1; 3*i < 1000; i++){
        sum += 3 * i;
    }
    for(int i = 1; 5*i < 1000; i++){
        sum += 5 * i;
    }
    for(int i = 1; 15*i < 1000; i++){
        sum -= 15 * i;
    }
    cout << "problem 1: " << sum << endl;
}

void problem_2(){
    int leader = 2;
    int follower = 1;
    int sum = 0;
    while(leader < 4000000){
        if(leader%2 == 0)
            sum+= leader;
        int temp = leader;
        leader += follower;
        follower = temp;
    }
    cout << "problem 2: " << sum << endl;
    
}

void problem_3(){
    // forgot how i did it.



}

void problem_4(){
    int j;
    int k = 999;
    bool done = false;
    for(j = 999; j > 850; j--){
        for(k = 999; k > 850; k--){
            int temp = j*k;
            if(is_palindrome(temp)){
                done = true;
                break;
            }
        }
        if(done)
            break;
    }
    
    cout << "problem 4: " << j*k << endl;
}

void problem_5(){
    cout << "problem 5: " << 19*17*13*11*7*5*9*16 << endl;
}

void problem_6(){
    long ssq = 0;
    for(int i = 1; i < 101; i++){
        ssq += i * i;
    }
    cout << "problem 6: " << 5050*5050 - ssq<< endl;
}

void problem_7(){
    int n_of_primes = 6;
    int i = 15;
    int pr[10001];
    pr[0] = 2; pr[1] = 3; pr[2] = 5;
    pr[3] = 7; pr[4] = 11; pr[5] = 13;
    
    
    // start from 15, so 2,3,5,7,11,13 are included
    while(n_of_primes!= 10001){
        if(is_prime(pr, n_of_primes, i)){
            pr[n_of_primes] = i;
            n_of_primes++;
        }
        i += 2;
    }
    cout << "problem 7: " << i-2 << endl;
}

void problem_8(){
    ifstream in_file;
    in_file.open("problem_8.txt");
    if(in_file.fail()){
        cout << "problem_8.txt" << endl;
        exit(0);
    }
    string line;
    string number = "";
    for(int i = 0; i < 20; i++){
        getline(in_file, line);
        number = number + line;
    }
    int64_t maxproduct = 0;
    for(int i = 0; i < 988; i++){
        int64_t temp = (number[i]-'0')*(number[i+1]-'0')*(number[i+2]-'0')*(number[i+3]-'0')*(number[i+4]-'0')*(number[i+5]-'0')*(number[i+6]-'0')*(number[i+7]-'0')*(number[i+8]-'0')*(number[i+9]-'0')*(number[i+10]-'0')*(number[i+11]-'0')*(number[i+12]-'0');
        if(temp > maxproduct){
            maxproduct = temp;
        }
    }
    cout << "incorrect answer" << endl;
    cout << "problem 8: " << maxproduct << endl;
}

void problem_9(){
    int problem_9 = 0;
    for(int i = 1; i < 332;i++){
        for(int j = 2; j < 499;j++){
            int k = 1000 - i - j;
            if(k*k == i*i + j*j)
                problem_9 = i*j*k;
        }
    }
    cout << "problem 9: " << problem_9 << endl;

}

void problem_10(){
    int n_of_primes = 6;
    int i = 15;
    int pr[200000];
    pr[0] = 2; pr[1] = 3; pr[2] = 5;
    pr[3] = 7; pr[4] = 11; pr[5] = 13;
    
    while(i < 2000000){
        if(is_prime(pr, n_of_primes, i)){
            pr[n_of_primes] = i;
            n_of_primes++;
        }
        i += 2;
    }
    int64_t sum = 0;
    for(int i = 0; i < n_of_primes; i++){
        sum += pr[i];
    }
    cout << "problem 10: " << sum << endl;
}

void problem_11(){
    matrix a;
    ifstream in_file;
    in_file.open("problem_11.txt");
    if(in_file.fail()){
        cout << "problem_11.txt" << endl;
        exit(0);
    }
    string line;
    for(int i = 0; i < a.size; i++){
        getline(in_file, line);
        a.parsematrix2(line, i);
    }
    long v = a.maxhorizontalproduct();
    long d = a.maxdiagonalproduct();
    long h = a.maxhorizontalproduct();
    
    long largest = (v > d) ? v : d;
    largest = (largest > h) ? largest : h;
    
    cout << "problem 11: " << largest << endl;
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
    cout << "problem 12" << endl;
    cout << "number of factors: " << maxcount << endl;
    cout << "the number is: " << contingency << endl;
}

void problem_13(){
    string sum[100];
    int count = 0;
    int reset = 0;
    
    ifstream in_file;
    in_file.open("problem_13.txt");
    if(in_file.fail()){
        cout << "problem_13.txt" << endl;
        exit(0);
    }
    string omg;
    getline(in_file, omg);

    for(int i = 0; i < 5000; i++){
        sum[count] += omg[i];
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
    cout << "problem 13: " << result << endl;
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
    cout << "problem 14" << endl;
    cout << "maxstarter is: " << maxstarter << endl;
    cout << "maxcount is: " << maxcount << endl;
}

void problem_15(){
    //return 40!/(20! * 20!);
    cout << "problem 15: " << endl;
}

void problem_16(){
    string horolo = "2";
    for(int i = 0; i < 999; i ++){
        horolo = string_adder(horolo, horolo);
    }
    int s = 0;
    cout << "problem 16" << endl;
    cout << "2^1000 = " << horolo << endl;
    for(int i = 0; i < horolo.length(); i++){
        s += horolo[i] - '0';
    }
    cout << "sum of digits: " << s << endl;
}


void problem_17(){
    // sum of letters from one to one thousand
    int digit[9] = {3,3,5,4,4,3,5,5,4};
    int hundred = 7;
    int tens[9] = {3,6,6,5,5,5,7,6,6};
    int teens[9] = {6,6,8,8,7,7,9,8,8};
 
    int one_to_nine = 0;
    for(int i = 0; i < 9; i++)
        one_to_nine += digit[i];
    
    int ten_to_nineteen = 0;
    for(int i = 0; i < 9; i++)
        ten_to_nineteen += teens[i];
    ten_to_nineteen += 3;
    
    int twenty_to_ninety_nine = 0;
    twenty_to_ninety_nine += 8 * one_to_nine;
    for(int i = 1; i < 9; i++)
        twenty_to_ninety_nine += 10 * tens[i];
 
    int one_to_ninety_nine = one_to_nine + ten_to_nineteen + twenty_to_ninety_nine;
    cout << "problem 17" << endl;
    cout << "1 to 99: " << one_to_ninety_nine << endl;
 
    int result;
    result = 10 * one_to_ninety_nine;      // last two digits for 1-999
    result += (hundred * 9);               // we have 9 instances where a number ends with two 0's
    result += ((hundred + 3) * 99 * 9);    // we have 99 * 9 instances where last two digits != 00
    result += one_to_nine * 100;           // prefix for hundred
    result += 11;                          // one hundred
    cout << "1 to 1000: " << result << endl;
}

void problem_18(){
    ifstream in_file;
    in_file.open("problem_18.txt");
    if(in_file.fail()){
        cout << "problem_18.txt" << endl;
        exit(0);
    }
    // read in text file
    
    string line;    string tree = "";
    for(int i = 0; i < 15; i++){
        getline(in_file, line);
        tree = tree + line;
    }
    // combine the entire text file into a string
    
    const int size = 120;
    int numbers[size];
    parse_string_to_array(numbers, tree, size);
    node nodes[size];
    for(int i = 0; i<120; i++){
        nodes[i].setval(numbers[i]);
    }
    //convert the string to an array of nodes
    
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < i + 1; j++){
            int current = i * (i + 1) / 2 + j;
            int leftchild = current + i + 1;
            nodes[current].leftchild = &nodes[leftchild];
            nodes[current].rightchild = &nodes[leftchild+1];
        }
    }
    
    /*
     the variable i is the level index, starting 0 from the top of the triangle.
     the variable j is the offseet index, starting 0 from the leftiest node in a level.
     the variable current calculates the index of the node in a given level and offset in the array.
     the variable leftchild finds the index of the leftchild of the node with the index current.
     */
    
    int* max = new int(0);
    
    depth_first_addition(max, &nodes[0], 0);
    
    cout<< "problem 18: " << *max << endl;
    delete max;
}

void problem_19(){
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int day_offset = 364; // jan 1
    /*
     i looked up the first day of 1901, and happened to be tuesday
     365%7 == 1, and there are tuesday - sunday == 2.
     so i reduced 365 by one to 'correct' the offset
    */
    int year_offset = 1901; // year 1901
    int sundays_on_the_first = 0;
    
    while(year_offset != 2001){
        for(int i = 1; i < 13; i++){
            int number_of_days_in_a_month;
            if(i == 2 && year_offset%4 == 0 && year_offset != 2000){
                number_of_days_in_a_month = months[i-1] + 1;
            }
            else if(i == 2 && year_offset%4 == 0 && year_offset%100 == 2000){
                number_of_days_in_a_month = months[i-1];
            }
            else
                number_of_days_in_a_month = months[i-1];
            
            day_offset += number_of_days_in_a_month;
            if(day_offset%7 == 0)
                sundays_on_the_first++;
        }
        year_offset++;
    }
    cout << "problem 19: " << sundays_on_the_first << endl;
}

void problem_20(){
    string number = "100";
    string result = "1";
    for(int i = 0; i < 100; i++){
        result = string_multiplier(result, number);
        number = string_decrement(number);
    }
    int sum = 0;
    for(int i = 0; i < result.length(); i++){
        sum += result[i] - '0';
    }
    cout << "problem 20: " << sum << endl;
    
}

void problem_21(){
    // amicable numbers, a pair of numbers whose sums of each's factors are equal
    // e.g. d(220) = 284 and d(284) = 220; 284 and 220 are amicable pairs, and each is an amicable number
    int amicables[40]; int friends = 0;
    
    for(int test = 2; test < 10000; test++){
        if(is_amicable(test) > 0){
            amicables[friends++] = test;
        }
    }
    
    int sum = 0;
    for(int i = 0; i < friends; i++){
        sum += amicables[i];
    }
    cout << "problem 21: " << sum << endl;
}

void problem_22(){
    ifstream in_file;
    in_file.open("problem_22.txt");
    if(in_file.fail()){
        cout << "problem_22.txt" << endl;
        exit(0);
    }
    
    string naaaaame;
    getline(in_file, naaaaame);
    person people[5163];
    int count = parse_string_to_names(people, naaaaame);
    alphabetical_insertion_sort(people, count);
    
    int sum = 0;
    for(int i = 0; i < count; i++){
        sum += (i + 1) * people[i].value;
    }
    
    cout << "problem 22: " << sum << endl;
}

void problem_23(){
    
    int abundant[7000];
    for(int i = 0; i < 7000; i++){
        abundant[i] = 0;
    }
    int count = 0;
    // initialize the array of abundant numbers
    for(int i = 12; i < 28124; i++){
        int sum_of_factors = 1;                 // sum starts with 1
        for(int j = 2; j <= sqrt(i); j++){
            if(i%j == 0){
                sum_of_factors += j;
                if(j != sqrt(i))
                    sum_of_factors += i/j;      // in case the factor is a sqrt
            }
        }
        if(sum_of_factors > i){
            abundant[count] = i;
            count++;
        }
    }
    
    int sum_of_two_abundant[29000];
    for(int i = 0; i < 29000; i++)
        sum_of_two_abundant[i] = 0;
    int size_of_sotb = 0;
    // initialize the array of the sum of two abundant numbers less than 28124
    
    for(int i = 0; i < count; i++){
        for(int j = i; j < count; j++){
            int temp = abundant[i] + abundant[j];
            if(temp < 28124){
                if(!number_exists_in_array(sum_of_two_abundant, temp, size_of_sotb)){
                    sum_of_two_abundant[size_of_sotb] = temp;
                    size_of_sotb++;
                }
            }
        }
    }
    // find unique sum of two abundant numbers less than 28124
    
    
    int sum_from_1_to_28123 = 0;
    for(int i = 1; i <= 28123; i++)
        sum_from_1_to_28123 += i;

    int temp_sum = 0;
    for(int i = 0; i < size_of_sotb; i++){
        temp_sum += sum_of_two_abundant[i];
    }

    // sum of numbers that aren't sum of two abundant numbers
    // = sum from 1 to 28123 - sum of sum of two abundant numbers
    
    cout << "problem 23: " << sum_from_1_to_28123 - temp_sum << endl;

}

void problem_24(){
    int factorials[9];
    for(int i = 0; i < 9; i++){
        factorials[i] = factorial(i+1);
    }
    
    int quotients[10];
    for(int i = 0; i < 10; i++){
        quotients[i] = 0;
    }
    
    int million = 1000000;
    
    for(int i = 0; i < 9; i++){
        quotients[i] = million / factorials[8-i];
        million = million - factorials[8-i] * quotients[i];
    }
    
    for(int i = 0; i < 10; i++){
        cout << quotients[i] << endl;
    }
    // each kth element in the array quotients contains a number n such that
    // nth number in the list 0 to 9 corresponds to the kth digit of the millionth lexicographic number.
    // (millionth in this case)
    // and whenever we take a number from the list 0 to 9, we remove it from the list because each number is used only once.
    // for example, in problem 24 we have 2662512200.
    // we take 2nd digit from 0-9, 2 (actually starts from 0th, not 1st)
    // do the same until we meet zero.
    // then we have 27839156xx
    // finish up using smaller numbers first. = 2783915604
    // because zero in the end means we went for million and first lexicographic number,
    // we go back by one by finding one less lexicographic from 604, which is 460.
    // the answer is 2783915460
}

void problem_25(){
    cout << fibonacci("1", "1", 3) << endl;
    // string adder
}

void problem_26(){
    
}














void problem_67(){
    ifstream in_file;
    in_file.open("problem_67.txt");
    if(in_file.fail()){
        cout << "problem_67.txt" << endl;
        exit(0);
    }
    // read in text file
    
    string line;    string tree = "";
    for(int i = 0; i < 100; i++){
        getline(in_file, line);
        tree = tree + line;
    }
    // combine the entire text file into a string
    
    const int size = 5050;
    int numbers[size];
    parse_string_to_array(numbers, tree, size);
    node nodes[size];
    for(int i = 0; i<5050; i++){
        nodes[i].setval(numbers[i]);
    }
    //convert the string to an array of nodes
    
    for(int i = 98; i > 0; i--){
        for(int j = 0; j < i + 1; j++){
            int current = i * (i + 1) / 2 + j;
            int leftchild = current + i + 1;
            if(nodes[leftchild].val_is() > nodes[leftchild+1].val_is())
                nodes[current].addval(nodes[leftchild].val_is());
            else
                nodes[current].addval(nodes[leftchild+1].val_is());
        }
    }
    
    if(nodes[1].val_is() > nodes[2].val_is())
        nodes[0].addval(nodes[1].val_is());
    else
        nodes[0].addval(nodes[2].val_is());
    
    cout<< "problem 67: " << nodes[0].val_is() << endl;
    
    // solution by username 'mather' from projecteuler.net/thread=18
}
