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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)   return head;
         ListNode* temp = head; 
         ListNode* tail = head; 
         int length = 1; 
         while(temp->next != NULL){
              length++;
              temp = temp->next ;
         }
         tail = temp;
         if (k % length == 0) return head;
         k = k % length ;
         tail->next = head;
         temp = head;
        for(int i = 1 ; i < length - k ; i++){
          temp = temp->next;
        }
        tail = temp;
        head = temp->next;
        tail->next = NULL;


        return head;

    }
};