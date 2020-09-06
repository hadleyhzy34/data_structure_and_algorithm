//
//  main.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 13.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include "singly_linked_list_tutorial.cpp"
#include "21_merge_sorted_lists.cpp"
#include "83_Remove_duplicats_from_sorted_list.cpp"
#include "141_linked_list_cycle.cpp"
#include "203_remove_linked_list_elements.cpp"
#include "206_reverse_linked_list.cpp"
#include "234_palindrome_linked_list.cpp"
using namespace std;

void push(Node **, int);
void insert(ListNode **, int);
void insert1(ListNode *, int);

void display(struct ListNode *);

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    int i=8;
//    int *ptr;
//    ptr=&i;
//    int **ptr_1=&ptr;
//    cout<<**ptr_1<<" "<<i<<endl;
//
//    cout<<*ptr_1<<" "<<ptr<<" "<<&i<<endl;
//
//    cout<<ptr_1<<" "<<&ptr<<endl;

    //it's possible that more than one pointer points to the same variable
//    int i=8;
//    int *ptr;
//    ptr=&i;
//    int *ptr1;
//    ptr1=ptr;
//    cout<<ptr1<<" "<<ptr<<" "<<*ptr1<<" "<<*ptr<<endl;
    
//    Node *head = NULL;
//    push(&head,9);
//    push(&head,10);
    //note that if you use struct with constructor, then you should also malloc to initialize the struct instead of new, ListNode *head = new ListNode;
    ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    //if linked list is not initialized to be null, then it will get bad access of memory to display last node of linked list
    //test 83
    head = NULL;
//    insert(&head,10);
//    insert(&head,9);
//    insert(&head,9);
//    insert(&head,9);
//    insert(&head,8);
//    insert(&head,8);
//    insert(&head,8);
//    insert(&head,8);
//    insert(&head,2);
//    insert(&head,2);
//    insert(&head,1);
//    Solution83 test1;
//    display(test1.deleteDuplicates(head));
    
    //detect loop in a linked list
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);

    
    /* Create a loop for testing */
//    head->next->next->next->next->next = head->next->next;
    
//    Solution141_1 test1;
//      if (test1.hasCycle(head))
//          cout << "Loop found";
//      else
//          cout << "No Loop";
    //203test
//    Solution203 test1;
//    display(test1.removeElements(head,2));
    
    //206test
//    Solution206_2 test1;
////    display(head);
//    display(test1.reverseList(head));
//    int x=8;
//    int y=9;
//    int *ptr1=&x;
//    int *ptr2 = ptr1;
//    int *ptr3 = &y;
//    cout<<&ptr1<<endl;
//    cout<<&ptr2<<endl;
//    cout<<*ptr2<<endl;
//    cout<<*ptr3<<endl;
//    ptr1 = ptr3;
//    cout<<*ptr2<<endl;
//    cout<<*ptr1<<endl;
//    cout<<*ptr3<<endl;
//
    //test234
    Solution234 test;
    cout<<test.isPalindrome(head);
    

    return 0;
}

//each node is a pointer to object node,input argument is pointer to node(pointer)
void push(Node ** head_ref, int new_data){
    Node * new_node = new Node();
    new_node->data = new_data;
    //note that if input argument is Node * head_ref, then *head_ref is type node, if input argument is Node ** head_ref, then *head_ref is type Node*, check double pointers topic
    //new_node->next = &(*head_ref) is available if input argument is Node * head_ref, but &(*head-ref)=new_node is not assignable
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    cout<<(*head_ref)->data<<endl;
}


//the core reason why we use pointer to pointer is that if we use pointer to struct listnode, then when doing step node = temp, it will change address of this pointer node, which is copy of input argument, then it will point to something else and value that input argument points is not changed
//on the other hand, address of pointer to pointer is not changed inside insert function
void insert(ListNode **node, int new_data){
    ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = new_data;
    temp->next = (*node);
    (*node) = temp;
}

void insert1(ListNode *node, int new_data){
    ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
     cout<<node<<endl;
    cout<<temp<<endl;
    temp->val = new_data;
    temp->next = node;
    node = temp;
    cout<<node->val<<endl;
    cout<<node<<endl;
}

void display(struct ListNode *node) {
    ListNode *ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr=node;
   while (ptr!=NULL) {
       cout<<ptr<<endl;
       cout<< ptr->val <<" ";
       ptr = ptr->next;
   }
}
