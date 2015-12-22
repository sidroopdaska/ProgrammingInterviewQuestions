//  Dynamic Programming - Subset Sum Problem
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


int main(int argc, const char * argv[]) {
    int arr[]{3,5,4,7,2,1};
    vector<int> solution;
    SubSet(arr, 6, 0, 9, solution);
    
    return 0;
}
