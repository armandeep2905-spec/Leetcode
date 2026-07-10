/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head ;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr != NULL){
           next = curr->next ; // info abt next node before breaking
           curr->next = prev; // reverse the connection
           prev = curr; // next prev
           curr = next; // move to the next node
        }
       return prev;
    }
};