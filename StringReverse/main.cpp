//
//  main.cpp
//  StringReverse
//
//  Created by Siddharth Sharma on 23/11/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    
    string str = "Siddharth";
    char temp = '\0';
    for(int i = 0 ; i <= str.length() / 2; i++) {
        int end  = str.length() - 1 - i;
        temp  = str[i];
        str[i] = str[end];
        str[end] = temp;
    }
    
    cout << str << endl;
    return 0;
}

