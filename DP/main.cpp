//
//  main.cpp
//  DP
//
//  Created by Siddharth Sharma on 06/12/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void SubSet(int arr[], int n, int i, int sum, vector<int> solution){
    if(sum == 0){
        for(vector<int>::iterator itr = solution.begin(); itr!= solution.end(); itr++)
            cout << *itr;
        
        cout <<endl;
        return;
    }
    if (i >= n) return ;

    if(arr[i] <= sum){
        //include it or dont
        SubSet(arr, n, i+1, sum, solution);
        solution.push_back(arr[i]);
        SubSet(arr, n, i+1, sum-arr[i], solution);
    } else {
        SubSet(arr, n, i+1, sum, solution);

    }
}

int longestPalinSubsequence(string str, int i, int j, int count){
    if(i > j){
        return count;
    }
    if(str[i] == str[j]){
        if(i == j){
            count += 1;
        } else
            count += 2;
        
        return longestPalinSubsequence(str, i+1, j-1, count);
    } else {
        return max(longestPalinSubsequence(str, i, j-1, count), longestPalinSubsequence(str, i+1, j, count));
    }
  
}
// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
    int n = strlen(str);
    int i, j, cl;
    int L[n][n];  // Create a table to store results of subproblems
    
    
    // Strings of length 1 are palindrome of lentgh 1
    for (i = 0; i < n; i++)
        L[i][i] = 1;
    
    // Build the table. Note that the lower diagonal values of table are
    // useless and not filled in the process. The values are filled in a
    // manner similar to Matrix Chain Multiplication DP solution s
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
                L[i][j] = 2;
            else if (str[i] == str[j])
                L[i][j] = L[i+1][j-1] + 2;
            else
                L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    
    return L[0][n-1];
}

int main(int argc, const char * argv[]) {
    //int arr[]{3,5,4,7,2,1};
    //vector<int> solution;
    //SubSet(arr, 6, 0, 9, solution);
    string str = "AABCDEBAZ";
    int count = 0;
    cout << longestPalinSubsequence(str, 0, 8, count);
    
    return 0;
}
