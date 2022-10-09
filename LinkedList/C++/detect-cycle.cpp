//Problem statement: Detect cycle in a singly linked list

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};


bool detectCycle(Node* head)
{
    Node *slow = head, *fast = head;
 
    while (fast && fast->next)
    {
        // move slow by one pointer
        slow = slow->next;
 
        // move fast by two pointers
        fast = fast->next->next;
 
        // if they meet any node, the linked list contains a cycle
        if (slow == fast) {
            return true;
        }
    }
 
    return false;
}
 
int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next = head->next->next;
 
    if (detectCycle(head)) {
        cout << "Cycle Found";
    }
    else {
        cout << "No Cycle Found";
    }
 
    return 0;
}

//Output: Cycle Found
