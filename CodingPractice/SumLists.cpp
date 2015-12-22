//
//  Partition.cpp
//  CodingPractice
//
//  Created by Siddharth Sharma on 08/11/2015.
//  Copyright © 2015 Siddharth. All rights reserved.
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
//Node* createNewNode(int data) {
//    
//    Node *new_node = new Node;
//    new_node->data =data;
//    new_node->next = nullptr;
//    return new_node;
//}
//
//Node* insertEnd(Node *start, int data) {
//    
//    Node *new_node = createNewNode(data);
//    if (start == nullptr) {
//        start = new_node;
//    } else {
//        new_node->next = start;
//        start = new_node;
//    }
//    
//    return start;
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
//Node* sum(Node *list1, Node *list2){
//    Node *result = nullptr;
//    Node *current = nullptr;
//    int carry = 0;
//    while(list1 != nullptr || list2 != nullptr){
//        Node *node = new Node;
//        if( list1 == nullptr){
//            node->data = carry + list2->data;
//        } else if (list2 == nullptr) {
//            node->data = carry + list1->data;
//        } else {
//            node->data = carry + list1->data + list2->data;
//        }
//        
//        if (node->data >= 10) {
//            carry = node->data / 10;
//            node->data = node->data % 10;
//        } else {
//            carry = 0;
//        }
//        
//        node->next = nullptr;
//        if(result == nullptr){
//            result = node;
//            current = node;
//        } else {
//            current->next = node;
//            current = node;
//        }
//        
//        if(list1 != nullptr)
//            list1 = list1->next;
//        
//        if(list2 != nullptr)
//            list2 = list2->next;
//    }
//    
//    return result;
//}
//
//int main() {
//    Node *start1 = nullptr;
//    Node *start2 = nullptr;
//    
//    start1 = insertEnd(start1 ,1);
////    start1 = insertEnd(start1 ,1);
////    start1 = insertEnd(start1 ,7);
//
//    start2 = insertEnd(start2 ,5);
//    start2 = insertEnd(start2 ,0);
//    start2 = insertEnd(start2 ,0);
//    Node *result = sum(start1, start2);
//    display(result);
//    
//    return 0;
//}