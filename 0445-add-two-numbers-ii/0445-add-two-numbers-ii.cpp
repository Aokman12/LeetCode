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
private:
    ListNode* reverseit(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* temp;
        while (head) {
            temp = head->next;
            head->next = prev;
            
            prev = head;
            head = temp;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = reverseit(l1);
        ListNode* temp2 = reverseit(l2);
        
        int carry = 0;
        int totalsum = 0;
        ListNode* ans = new ListNode();
        
        while(temp1 || temp2){
            if(temp1){
                totalsum += temp1->val;
                temp1 = temp1->next;
            }
            if(temp2){
                totalsum += temp2->val;
                temp2 = temp2->next;
            }
            
            ans->val = totalsum % 10;
            carry = totalsum/10;
            ListNode* head = new ListNode(carry);
            head->next = ans;
            ans = head;
            totalsum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};