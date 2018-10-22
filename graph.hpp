//
//  graph.hpp
//  euler2
//
//  Created by Joo Seung Lee on 7/28/18.
//  Copyright © 2018 Joo Seung Lee. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class node{
private:
    int val;
public:
    node();
    node(int input);
    //bool has_child();
    void setval(int input);
    void addval(int input);
    int val_is();
    node* leftchild = NULL;
    node* rightchild = NULL;
};

#endif /* graph_hpp */
