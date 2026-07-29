/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    
        if(head == NULL) return head;
        Node* oldTemp = head->next; // we can also start from the head
        Node* newHead = new Node(head->val);
        Node* newTemp = newHead;
        unordered_map < Node* , Node* >m ;
        m[head] = newHead ;  // this is initial entry in the map 

        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp -> val);
             m[oldTemp] = copyNode;
             newTemp->next = copyNode;
             oldTemp = oldTemp->next ; 
             newTemp = newTemp->next ;
        }

        oldTemp = head ; 
        newTemp = newHead ;

        while(oldTemp != NULL){
            newTemp -> random = m[oldTemp->random]; // we are traversing both the linked list simultaneously , so we automatically get coressponding nodes

            oldTemp = oldTemp->next ; 
            newTemp = newTemp ->next ;

        }

        return newHead ;
    }
};