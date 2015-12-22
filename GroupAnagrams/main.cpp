//
//  main.cpp
//  GroupAnagrams
//
//  Created by Siddharth Sharma on 26/11/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
int determineASCIIVal(string str){
    int val = 0;
    for(int i =0 ; i < str.length(); i++){
        val += str[i];
    }
    return val;
}
void groupAnagrams(string str[], int n){
    
    map<int, int> m;
    map<int,int>::iterator itr;
    
    string *results = new string[n];
    for(int i = 0; i < n; i++ ){
        int val = determineASCIIVal(str[i]);
        cout << val << endl;
        itr = m.find(val);
        if(itr != m.end()){
            (*itr).second++;
        } else {
            m.insert(pair<int,int>(val,1));
        }
    }
    map<int,int>::iterator prev = m.begin();
    for(itr = ++m.begin(); itr!=m.end(); itr++){
        itr->second += prev->second;
        prev = itr;
    }
    
    for(int i = n-1; i >= 0; i--){
        itr = m.find(determineASCIIVal(str[i]));
        results[itr->second-1] = str[i];
        itr->second--;
    }
    
    for(int i = 0;i < n;i++){
        cout << results[i] << " ";
    }
}
*/

void groupAnagrams(string str[], int n){
    multimap<string, string> m;
    string key;
    for(int i = 0; i < n; i++){
        key = str[i];
        sort(key.begin(), key.end());
        m.insert(pair<string,string>(key, str[i]));
    }
    multimap<string, string>::iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++){
        cout << itr->second<< " ";
    }
}

void findthelargestcontinuossum(int arr[], int size){
    
    int total = arr[0];
    int current = arr[0];
    for(int i = 1; i < size; i++){
       
        if(current + arr[i] > 0)
            current = current + arr[i];
        else
            current = 0;
        
        total = total + current;
    }
    
    cout << "the sum = " << total <<endl;
}

int main(int argc, const char * argv[]) {
    
    //string str[] = {"god", "bee", "dog"};
    //int size = sizeof(str)/sizeof(str[0]);
    
   // groupAnagrams(str, size);
   
    int arr[]{1,2,3,-5,25};
    int size = sizeof(arr)/sizeof(arr[0]);

    findthelargestcontinuossum(arr, size);
    
    return 0;
}
