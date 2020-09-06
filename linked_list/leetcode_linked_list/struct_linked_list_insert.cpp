//
//  struct_linked_list_insert.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 13.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// only for the 1st Node
void initNode(struct Node *head,int n){
    head->data = n;
    head->next =NULL;
}

// apending
void addNode(struct Node *head, int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    Node *cur = head;
    while(cur) {
        if(cur->next == NULL) {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}


void display(struct Node *head) {
    Node *list = head;
    while(list) {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
    cout << endl;
}

int main()
{
    struct Node *newHead;
    struct Node *head = new Node;
    
    initNode(head,10);
    display(head);

    addNode(head,20);
    display(head);

    addNode(head,30);
    display(head);

    addNode(head,35);
    display(head);

    addNode(head,40);
    display(head);

    insertFront(&head;,5);
    display(head);

    int numDel = 5;
    Node *ptrDelete = searchNode(head,numDel);
    if(deleteNode(&head;,ptrDelete))
        cout << "Node "<< numDel << " deleted!\n";
    display(head);

    cout << "The list is reversed\n";
    reverse(&head;);
    display(head);

    cout << "The list is copied\n";
    copyLinkedList(head,&newHead;);
    display(newHead);

    cout << "Comparing the two lists...\n";
    cout << "Are the two lists same?\n";
    if(compareLinkedList(head,newHead))
        cout << "Yes, they are same!\n";
    else
        cout << "No, they are different!\n";
    cout << endl;

    numDel = 35;
    ptrDelete = searchNode(newHead,numDel);
    if(deleteNode(&newHead;,ptrDelete)) {
        cout << "Node "<< numDel << " deleted!\n";
        cout << "The new list after the delete is\n";
        display(newHead);
    }
    cout << "Comparing the two lists again...\n";
    cout << "Are the two lists same?\n";
    if(compareLinkedList(head,newHead))
        cout << "Yes, they are same!\n";
    else
        cout << "No, they are different!\n";
    
    cout << endl;
    cout << "Deleting the copied list\n";
    deleteLinkedList(&newHead;);
    display(newHead);
    return 0;
}
