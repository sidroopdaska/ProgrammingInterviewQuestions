////
////  LL.cpp
////  CodingPractice
////
////  Created by Siddharth Sharma on 08/11/2015.
////  Copyright © 2015 Siddharth. All rights reserved.
////
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
//
//Node *start = nullptr;
//Node *current = nullptr;
//
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
//        current = new_node;
//    } else {
//        current->next = new_node;
//        current = new_node;
//    }
//}
//void display() {
//    
//    Node *temp = start;
//    while(temp!=nullptr) {
//        cout << temp->data << " ";
//        temp = temp->next;
//    }
//}
//
//
//void removeDuplicates() {
//    set<int> s;
//    Node *temp = start;
//    Node *prev = nullptr;
//    Node *temp1;
//    while (temp!=nullptr) {
//        
//        if(!s.count(temp->data)) {
//            s.insert(temp->data);
//        } else {
//            temp = prev;
//            temp1 = temp->next;
//            temp->next = temp->next->next;
//            delete temp1;
//        }
//        prev = temp;
//        temp = temp->next;
//    }
//}
//
//int main() {
//    insertEnd(3);
//    insertEnd(1);
//    insertEnd(2);
//    insertEnd(3);
//    insertEnd(5);
//    insertEnd(5);
//    insertEnd(3);
//    insertEnd(5);
//    removeDuplicates();
//    display();
//    return 0;
//}