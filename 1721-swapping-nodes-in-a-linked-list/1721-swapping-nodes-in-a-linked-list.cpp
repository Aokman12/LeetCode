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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL && head->next == NULL){
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* superFast = head;
        
        int c = k;
        while(--c){
            superFast = superFast->next;
        }
        
        while(superFast->next != NULL){
            fast = fast->next;
            superFast = superFast->next;
        }
        
        int count = 1;
        
        while(count != k){
            slow = slow->next;
            count++;
        }
        
        int temp = slow->val;
        slow->val = fast->val;
        fast->val = temp;
        
        return head;
    }
};