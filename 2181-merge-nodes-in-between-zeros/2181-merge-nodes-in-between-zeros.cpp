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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* brandNew = new ListNode(0);
        ListNode* ans = brandNew;
        head = head->next;
        int sum = 0; 
        
        while(head != NULL){
            if(head->val == 0){
                brandNew->next = new ListNode(sum);
                brandNew = brandNew->next;
                sum = 0;
            }
            else{
                sum = sum + head->val;
            }
            head = head->next;
        }
        
        return ans->next;
    }
};