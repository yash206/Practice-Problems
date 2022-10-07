#include <iostream>
#include <unordered_set>
using namespace std;
 
// A Linked List Node
struct Node
{
    int data;
    Node* next;
};
 
// function to create linked list
void push(Node*& head, int data)
{
    // create a new linked list node from the heap
    Node* newNode = new Node;
 
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
 
// Floyd’s cycle detection algorithm
bool detectCycle(Node* head)
{
    // take two pointers – `slow` and `fast`
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
    // we reach here if the slow and fast pointer does not meet
    return false;
}
 
int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);
 
    Node* head =NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(head, keys[i]);
    }
    // insert cycle
    head->next->next->next->next->next = head->next->next;
 
    if (detectCycle(head)) {
        cout << "Cycle Found";
    }
    else {
        cout << "No Cycle Found";
    }
    return 0;
}
/*
Output::
        Cycle Found
*/
