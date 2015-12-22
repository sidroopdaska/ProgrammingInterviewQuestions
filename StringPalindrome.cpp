//
//  StringPalindrome.cpp
//  CodingPractice
//
//  Created by Siddharth Sharma on 09/11/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//vector<string> findPermutations(string str) {
//    
//    if (str.length() == 1) {
//        vector<string> words;
//        words.push_back(str);
//        return words;
//    }
//    
//    vector<string> perms = findPermutations(str.substr(1));
//    char ch = str[0];
//    vector<string> results;
//    
//    for (vector<string>::size_type i = 0; i < perms.size(); i++) {
//        for (vector<string>::size_type j = 0; j < perms[i].length() + 1; j++) {
//            if(j == perms[i].length()) {
//                results.push_back((perms[i].substr(0, j) + ch));
//            } else {
//                results.push_back((perms[i].substr(0, j) + ch + perms[i].substr(j)));
//            }
//        }
//    }
//    
//    return results;
//}
//
//int main() {
//    
//    string str = "sidd";
//   
//    vector<string> str1 = findPermutations(str);
//    for (vector<string>::size_type  i = 0; i < str1.size(); i++) {
//        cout << str1[i] << " " << endl;
//    }
//    return 0;
//}

#include <stdio.h>
#include <math.h>

void printPowerSet(char *set, int set_size)
{
    /*set_size of power set of a set with set_size
     n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
    
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
        for(j = 0; j < set_size; j++)
        {
            /* Check if jth bit in the counter is set
             If set then pront jth element from set */
            if(counter & (1<<j))
                printf("%c", set[j]);
        }
        printf("\n");
    }
}

/*Driver program to test printPowerSet*/
//int main()
//{
//    char set[] = {'a','b','c'};
//    printPowerSet(set, 3);
//    
//    getchar();
//    return 0;
//}


void findPairs(int arr[]) {
    
    vector<int> myArr[6];
}
//int main() {
//    
//    int arr[] = {1,2,3,4,5};
//    findPairs(arr);
//    return 0;
//}


int main() {
    string str = " ";
    char temp;
    for(int i = 0 ; i <= str.length() / 2; i++) {
        int end = str.length() - 1 -i;
        temp = str[i];
        str[i] = str[end];
        str[end] = temp;
    }
    
    cout << str;
    return 0;
    
}