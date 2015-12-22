//
//  main.cpp
//  Dynamic Programming
//
//  Created by Siddharth Sharma on 06/12/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

// recursive method
int longestCommonSubstringRec(string str1, string str2, int pos1, int pos2, bool checkEqual){
    if(pos1 >= str1.length() || pos2 >= str2.length()){
        return 0;
    }
    if(checkEqual){
        if(str1[pos1] == str2[pos2]){
            return 1 + longestCommonSubstringRec(str1, str2, pos1+1, pos2+1, true);
        }else{
            return 0;
        }
    }
    int r1 = 0;
    if(str1[pos1] == str2[pos2]){
        r1 = 1 + longestCommonSubstringRec(str1, str2, pos1+1, pos2+1, true);
    }
    return max(r1,max(longestCommonSubstringRec(str1, str2, pos1+1, pos2, false), longestCommonSubstringRec(str1, str2, pos1, pos2+1,false)));
}

// Dynamic Programming - bottom up approach using tabulation
 int longestCommonSubstring(string str1, string str2){
     int **LCS = new int*[str1.length()+1];
     for(int i = 0; i < str1.length()+1; i++){
         LCS[i] = new int[str2.length()+1]();
     }
    
    int max = 0;
    for(int i=1; i <= str1.length(); i++){
        for(int j=1; j <= str2.length(); j++){
            if(str1[i-1] == str2[j-1]){
                LCS[i][j] = LCS[i-1][j-1] +1;
                if(max < LCS[i][j]){
                    max = LCS[i][j];
                }
            }
        }
    }
    return max;
}

string wordBreak(string str, unordered_map<string, int>& m, unordered_map<string, string>& memo){
    if(m.count(str))
        return str;
    
    int size = str.length();
    
    for(int i = 1; i <= size; i++){
        string prefix = str.substr(0,i);
        if(m.count(prefix)){
            string suffix = str.substr(i, size - i);
            if(memo.count(suffix)){
                return memo[suffix];
            } else{
                string segSuffix = wordBreak(suffix, m, memo);
                if(segSuffix != "\0"){
                    memo[str] = prefix + " " + segSuffix;
                    return memo[str];
                }
            }
        }
    }
    return "\0";
}

/* A utility function to check whether a word is present in dictionary or not.
 An array of strings is used for dictionary.  Using array of strings for
 dictionary is definitely not a good idea. We have used for simplicity of
 the program*/
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
        "icecream","and","go","i","love","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}

//prototype of wordBreakUtil
void wordBreakUtil(string str, int size, string result);

void wordBreak(string str)
{
    //last argument is prefix
    wordBreakUtil(str, str.size(), "");
}

// result store the current prefix with spaces between words
void wordBreakUtil(string str, int size, string result)
{
    //Process all prefixes one by one
    for (int i=1; i<=size; i++)
    {
        //extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);
        
        // if dictionary conatins this prefix, then we check
        // for remaining string. Otherwise we ignore this prefix
        // (there is no else for this if) and try next
        if (dictionaryContains(prefix))
        {
            // if no more elements are there, print it
            if (i == size)
            {
                // add this element to previous prefix
                result += prefix;
                cout << result << endl; //print result
                return;
            }
            wordBreakUtil(str.substr(i, size-i), size-i, result+prefix+" ");
        }
    }      //end for
}//end function
class Node {
    
public:
    int value;
    int min;
    Node(int v,int m){
        value = v;
        min = m;
    }
};
// if the idea is to return create a vector of vectors and add everything togethter and return
int main(int argc, const char * argv[]) {
    
    unordered_map<string, int> m;
    m["I"] = 1;
    m["like"] = 1;
    m["dog"] = 1;
    m["mango"] = 1;
    m["an"] = 1;
    string str1 = "Ianlikemango";
    unordered_map<string, string> memo;
    wordBreak(str1);
    stack<Node> s;
    s.top().min;

    return 0;
}
