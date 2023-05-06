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
        if(head == NULL){
            return NULL;
        }
        
        int count = 1;
        ListNode* newHead = head;
        ListNode* tail = head;
        
        while(tail->next != NULL){
            tail = tail->next;
            count++;
        }
        
        tail->next = head;
        
        if(k = k%count){
            for(int i=0;i<count-k;i++){
                tail = tail->next;
            }
        }
        
        newHead = tail->next;
        tail->next = NULL;
        
        return newHead;
    }
};