////
////  main.cpp
////  CodingPractice
////
////  Created by Siddharth Sharma on 15/10/2015.
////  Copyright © 2015 Siddharth. All rights reserved.
////
//
//#include <iostream>
//#include <string>
//#include <assert.h>
//#include <vector>
//#include <list>
//#include <algorithm>
//#include <numeric>
//#include <stack>
//#include <string>
//#include <unordered_map>
//#include <map>
//
//#include <stdio.h>
//#include <string.h>
//using namespace std;
//
//int partition(int arr[], int left, int right)
//{
//    int i = left, j = right;
//    int tmp;
//    int pivot = arr[(left + right) / 2];
//    
//    while (i <= j) {
//        while (arr[i] < pivot)
//            i++;
//        while (arr[j] > pivot)
//            j--;
//        if (i <= j) {
//            tmp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = tmp;
//            i++;
//            j--;
//        }
//    };
//    
//    return i;
//}
//
//void quickSort(int arr[], int left, int right) {
//    int index = partition(arr, left, right);
//    cout << index << endl;
//    if (left < index - 1)
//        quickSort(arr, left, index - 1);
//    if (index < right)
//        quickSort(arr, index, right);
//}
//
//int main() {
//    
//    int arr[] = {1, 12, 5, 26, 7, 14, 3, 7, 2};
//    quickSort(arr, 0, 8);
//    return 0;
//    
//}