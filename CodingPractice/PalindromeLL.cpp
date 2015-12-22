//
//  PalindromeLL.cpp
//  CodingPractice
//
//  Created by Siddharth Sharma on 08/11/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
//
//
//#include <stdio.h>
//#include <iostream>
//#include <map>
//#include <set>
//using namespace std;
//typedef struct Node {
//    int data;
//    Node *next;
//}Node;
//Node *start = nullptr;
//Node* createNewNode(int data) {
//    
//    Node *new_node = new Node;
//    new_node->data =data;
//    new_node->next = nullptr;
//    return new_node;
//}
//
//void insertEnd(int data) {
//    
//    Node *new_node = createNewNode(data);
//    if (start == nullptr) {
//        start = new_node;
//    } else {
//        new_node->next = start;
//        start = new_node;
//    }
//}
//
//void display(Node *start) {
//    
//    Node *temp = start;
//    while(temp!=nullptr) {
//        cout << temp->data << " ";
//        temp = temp->next;
//    }
//}
//
//Node* checkPalindrome(Node *temp) {
//    if(temp == nullptr)
//    {
//        return start;
//    }
//    Node *nd = checkPalindrome(temp->next);
//    if(nd == nullptr) {
//        return nullptr;
//    }
//    cout << nd->data << " " << temp->data << endl;
//    if(temp->data != nd->data){
//        return nullptr;
//    } else {
//        if(nd->next != nullptr)
//            return nd->next;
//        else
//            return nd;
//    }
//}
//
//int main() {
//   
//    insertEnd(1);
//    insertEnd(3);
//    insertEnd(4);
//    insertEnd(3);
//    insertEnd(1);
//    Node *result = checkPalindrome(start);
//    if(result == nullptr) {
//        cout << "NOT A PALIDROME";
//    } else {
//        cout << "PALINDROME";
//    }
//    
//    return 0;
//}