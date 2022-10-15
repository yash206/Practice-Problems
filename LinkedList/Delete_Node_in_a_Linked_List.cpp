/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
     // update current node as next node of current node
        ListNode* p= node->next;
        node->val= node->next->val;
        // update current node pointer to next node next pointer of current node
        node->next = node->next->next;
        p->next=NULL;
    }
};
