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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // check if k groups exists or not
        ListNode *temp = head ;
        int count = 1; // include the head node
        while(count <= k){
            if(temp == NULL) { return head;}
            temp = temp->next;
            count++;
        }
        // recursively call for rest of the linked list
        ListNode* rest = reverseKGroup(temp , k);

        // reverse the curr group 
        temp = head;
        count = 0;
        while(count < k){
        ListNode *next = temp->next;
        temp->next = rest ; 
        rest = temp;
        temp = next ; 
        count++;
        }
            return rest;
    }
};