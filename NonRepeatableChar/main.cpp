//
//  main.cpp
//  NonRepeatableChar
//
//  Created by Siddharth Sharma on 30/11/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void firstNonRepeatableChar(string str){
    
    unordered_map<char, int> m;
    for(int i = 0; i < str.length(); i++){
        m[str[i]]++;
    }
    
    for (int i = 0; i< str.length(); i++){
        if(m[str[i]] == 1){
            cout << "non repeatable char = " << str[i] << endl;
        }
    }
}

int main(){
    
    string str = "zaabccddsee";
    firstNonRepeatableChar(str);
    return 0;
}

// other method involves having a map called coutners and a vector called order.
// however, the one with teh hashmap is more optimal.