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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* lefty = dummy;
        
        for(int i=0;i<left-1;i++){
            lefty = lefty->next;
        }
        
        ListNode* curr = lefty->next;
        for(int i=0;i<right-left;i++){
            ListNode* forw = curr->next;
            curr->next = forw->next;
            forw->next = lefty->next;
            lefty->next = forw;
        }
        
        return dummy->next;
    }
};