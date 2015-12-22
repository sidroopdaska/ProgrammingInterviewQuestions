//
//  main.cpp
//  Pointers
//
//  Created by Siddharth Sharma on 25/11/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

#include <iostream>
using namespace std;
void playingWithPointers(int **c) {
    **c = 7;
    
}

int main(int argc, const char * argv[]) {
    int a = 6;
    int *b = &a;
    cout << *b << endl;
    playingWithPointers(&b);
    cout << *b;
    return 0;
}
