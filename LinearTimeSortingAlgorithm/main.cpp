//
//  main.cpp
//  LinearTimeSortingAlgorithm
//
//  Created by Siddharth Sharma on 25/11/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

//
//  main.cpp
//  LinearTimeSortingAlgorithms
//
//  Created by Siddharth Sharma on 24/11/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//

/*
 contains - radix sort, counting sort, bucekt sort
 */

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

// utility functions
int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    
    return max;
}
void print(int arr[], int n){
    //display the elements
    for(int i =0; i< n; i ++)
        cout << arr[i] << " ";
    
    cout<<endl;
}
// counting sort
void countingSort(int arr[], int n, int k){
    
    // 1st method: preferred
    /*vector<int> counters(k);
     
     for(int i = 0; i < n; i++){
     counters[arr[i]]++;
     }
     
     for(int i = 0; i < k; i++) {
     while(counters[i]>0){
     cout << i << " ";
     counters[i]--;
     }
     
     }*/
    
    //2nd method:
    int *counters = new int[k]();
    int *results = new int [n]();
    //update the count of n keys in the counters array
    for(int i = 0; i < n; i++)
        counters[arr[i]]++;
    
    //find the cumulative sum, this as a result stores the location of each key in the array
    for(int i = 1; i< k; i++)
        counters[i] += counters[i-1];
    
    for(int i = 0; i < n; i++){
        results[counters[arr[i]]-1] = arr[i];
        counters[arr[i]]--;
    }
    
    for(int i = 0; i< n; i++)
        arr[i] = results[i];
    
    print(arr, n);
}

//radix sort
void digitCountSort(int arr[], int n , int exp){
    int *counter = new int[10]();
    int *output = new int[n]();
    
    for(int i = 0; i< n; i++)
        counter[(arr[i]/exp)%10]++;
    
    for(int i = 1; i < 10; i++){
        counter[i] += counter[i-1];
    }
    
    // Build the output array, ensure stable sorting algo for duplicates.
    for (int i = n-1; i >= 0; i--)
    {
        output[counter[ (arr[i]/exp)%10 ] - 1] = arr[i];
        counter[ (arr[i]/exp)%10 ]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
}

void radixSort(int arr[], int n){
    int max = getMax(arr, n);
    for(int exp = 1; (max/exp) > 0; exp *= 10){
        digitCountSort(arr, n, exp);
    }
    print(arr, n);
    
}
// bucket sort
typedef struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
}Node;

typedef struct Bucket {
    int n_eles;
    Node *start;
    Node *current;
    //default constructor for struct
    Bucket() : n_eles(0), start(nullptr), current(nullptr) {}
}Bucket;

int getBucketIndex(int key, int range) {
    return key / range;
}


// insert at the end of the list to ensure we get a stable sorting algorithm
void insertElementIntoBucket(Bucket& b, int data) {
    Node *new_node = new Node(data);
    if (b.start == nullptr) {
        b.start = new_node;
        b.current = new_node;
    }
    else {
        b.current->next = new_node;
        b.current = new_node;
    }

    b.n_eles++;
    
}

Node* sortedInsert(Node *start, Node * newNode) {

    if(start == nullptr || start->data > newNode->data){
        newNode->next = start;
        start = newNode;
        return start;
    }
    Node *prev = nullptr;
    Node *current = start;
    while(current != nullptr && current->data < newNode->data){
        prev = current;
        current = current->next;
    }
    
    newNode->next = current;
    prev->next = newNode;
    
    return start;
}

void insertionSortBucket(Bucket *b) {
    // we have two lists. one = sorted, and the other one is unsorted. we take an element from the unsorted list and put it into the right place in the sorted list
    if(b->start == nullptr || b->start->next == nullptr)
        return;
    
    Node *result = b->start;
    Node *temp = b->start->next;
    result->next = nullptr;

    while(temp != nullptr){
        Node *ptr = temp;
        temp = temp->next;

        result = sortedInsert(result, ptr);
    }
    
    b->start = result;

}

void bucketSort(int arr[], int n) {
    //create an array of buckets
    Bucket *buckets = new Bucket[n]();
    
    // find the range and then add elements in the respective buckets
    int max = arr[0]; int min = arr[0]; int range = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    range = (max - min) / n + 1;
    int k = 0;
    for (int i = 0; i < n; i++) {
        k = getBucketIndex(arr[i], range);
        if (k == n)
            insertElementIntoBucket(buckets[k-1], arr[i]);
        else
            insertElementIntoBucket(buckets[k], arr[i]);
    }
    //sort each of the buckets using insertion sort
    for (int i = 0; i < n; i++) {
        cout << "here" << endl;
        insertionSortBucket(&buckets[i]);
    }
    //concatenate the elements in all the buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node *temp = buckets[i].start;
        while (temp != nullptr) {
            arr[index++] = temp->data;
            temp = temp->next;
        }
    }
}


int main() {
    int arr[] = {1,3,6,7,4,2,9 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, size);
    print(arr, size);
    return 0;
}