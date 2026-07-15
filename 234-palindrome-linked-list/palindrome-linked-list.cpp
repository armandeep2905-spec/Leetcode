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

   
   // bool isPalindrome(ListNode* head) {
        // approach one with using extra space 
        // stack<int> st;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     st.push(temp->val);
        //     temp=temp->next;
        // }

        // temp = head;
        // while(!st.empty() || temp != NULL){
        //     if(st.top() != temp->val) return false;
        //     temp= temp->next;
        //     st.pop();
        // }
        // return true;


        // approach 2 -> no extra space used 

         ListNode* reverseList(ListNode* head){
        ListNode* curr = head ;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }

        return prev;
    }

 bool isPalindrome(ListNode* head) {
    if(head==NULL || head->next ==NULL) return true; // edge case
        ListNode* slow = head;  ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){ // these are diff from normal conditons as we need to stop at second last node for even case and we are using middle one and not middle two
        
            fast = fast->next->next ;
            slow = slow->next;
        }
       
        ListNode* newHead =  reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second != NULL){ // running until second is NULL because we get exact number of comparisons this way
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        // reverseList(slow->next); //optional step as we only need true false
        return true;


    }
};