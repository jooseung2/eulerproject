//
//  graph.cpp
//  euler2
//
//  Created by Joo Seung Lee on 7/28/18.
//  Copyright © 2018 Joo Seung Lee. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "graph.hpp"

using namespace std;

node::node(){
    this->val = 0;
}

node::node(int input){
    this->val = input;
}
/*
bool node::has_child(){
    return haschild;
}
*/

void node::setval(int input){
    this->val = input;
}

void node::addval(int input){
    this->val += input;
}

int node::val_is(){
    return val;
}
/*
void node::rightbirth(node right){
    rightchild = &right;
    haschild = true;
}

void node::leftbirth(node left){
    leftchild = &left;
    haschild = true;
}
*/
