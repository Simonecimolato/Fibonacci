//
//  main.cpp
//  Simonacci
//
//  Created by Simone Cimolato on 18/12/16.
//  Copyright © 2016 Simone Cimolato. All rights reserved.
//
//  Use this code, but do not redistribuite it.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    
    long LastOne;
    
    cout<<"Hi, this program calculates the Fibonacci sequence, please enter the maximum number to calculate: ";
    cin>>LastOne;
    
    long num1 = 1;
    long num2 = 0;
    
    while (num1*2 + num2 <= LastOne){
        num1 += num2;
        cout<<num1<<endl;
        num2 += num1;
        cout<<num2<<endl;
    }
    return 0;
}
