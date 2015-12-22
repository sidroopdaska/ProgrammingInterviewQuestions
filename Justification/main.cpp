//
//  main.cpp
//  Justification
//
//  Created by Siddharth Sharma on 05/12/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
// Longest Common Subsequence

int DP(string str1, string str2, int i, int j){
    if (i >= str1.length() || j >= str2.length()) {
        return 0;
    }
    if (str1[i] == str2[j])
    {
        return 1 + DP(str1, str2, i+1, j+1);
    }
    else
        return max(DP(str1, str2, i+1, j), DP(str1, str2, i, j+1));

}

int DP(string str1, string str2){
    return DP(str1, str2, 0, 0);
}

int DP_tab(string str1, string str2){
    int **LCS = new int*[str1.length()+1];
    for(int i = 0; i < str1.length()+1; i++){
        LCS[i] = new int[str2.length()+1]();
    }
    int maximum = 0;
    for(int i = 1; i <= str1.length(); i++){
        for(int j = 1; j <= str2.length(); j++){
            if(str1[i-1] == str2[j-1]){
                LCS[i][j] = 1 + LCS[i-1][j-1];
            } else {
               LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
            }
            
            if(LCS[i][j] > maximum)
                maximum = LCS[i][j];
        }
    }
    string result;
    int j=str2.length();
    int i= str1.length();
    while(LCS[i][j] != 0){
        if(LCS[i][j] > LCS[i][j-1] && LCS[i][j] > LCS[i-1][j]){
            result.push_back(str1[i-1]);
            cout << i << j << endl;
            i = i-1; j = j-1;
        } else if (LCS[i][j] >= LCS[i][j-1] && LCS[i][j] > LCS[i-1][j]){
            j = j-1;
        } else {
            i = i-1;
        }
            
    }
    cout << result << endl;
    return maximum;

}

int main(){
    string str1 = "sidhellow";
    string str2 = "hellob";
    //cout << DP_LCS(str1, str2);
    return 0;
}