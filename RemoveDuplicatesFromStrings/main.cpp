//
//  main.cpp
//  RemoveDuplicatesFromStrings
//
//  Created by Siddharth Sharma on 30/11/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;

void removeDuplicatesFromString(string str){
    set<char> s;
    string result;
    for(int i = 0; i < str.length(); i++){
        if(!s.count(str[i])){
            s.insert(str[i]);
            result.push_back(str[i]);
        }
        else
            continue;
    }
    cout << result << endl;
    
}

int updateBit(int num, int i , bool bitIs1){
    int value = bitIs1 ? 1 : 0;
    int mask = ~(1 << i);
    return (num & mask) | (value << i);
}

int main(int argc, const char * argv[]) {

    string str = "tree traversal";
    //removeDuplicatesFromString(str);
    int num = 4;
    updateBit(num, 2, 0);
    cout << num;
    return 0;
}
