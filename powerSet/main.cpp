//
//  main.cpp
//  powerSet
//
//  Created by Siddharth Sharma on 06/12/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <iostream>
#include <vector>
#include  <set>
using namespace std;
#include <math.h>
// print subset of all sets
vector<vector<int>> printSubset(vector<int> set, int n) {
    static vector<vector<int>> allsubsets;
    if (n == 0) {
        allsubsets.push_back(vector<int>());
    }
    else {
        allsubsets = printSubset(set, n - 1);
        int item = set[n-1];
        vector<vector<int>> moresubsets;
        for (int i = 0; i < allsubsets.size(); i++) {
            vector<int> newsubset = allsubsets[i];
            newsubset.push_back(item);
            moresubsets.push_back(newsubset);
        }
        allsubsets.insert(allsubsets.end(), moresubsets.begin(), moresubsets.end());
    }
    return allsubsets;
}

vector<int> convertIntToSubset(vector<int> set, int i) {
    vector<int> subset;
    int index = 0;
    for (int j = i; j > 0; j = j >> 1) {
        if ((j & 1) != 0) {
            subset.push_back(set[index]);
        }
        index++;
    }
    return subset;
}

vector<vector<int>> getAllSubsets(vector<int> set, int n) {
    vector<vector<int>> allsubsets;
    for (int i = 0; i < pow(2, n); i++) {
        vector<int> subset = convertIntToSubset(set, i);
        allsubsets.push_back(subset);
    }
    return allsubsets;
}


int main() {
    vector<string> vec;
    vec.push_back("\0");
    cout << vec.size() << vec[0].length() << endl;
    set<int> s;
    s.insert(1);
    s.insert(1);
    cout << "done";
    
    return 0;
}


