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
    int pairSum(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return 0;
        }

        if(head->next->next == NULL){
            return head->val + head->next->val;
        }

        stack<int> st;
        st.push(head->val);
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast != NULL && fast->next != NULL){
                st.push(slow->val);
            }
        }

        // slow = slow->next;
        cout<<st.top() << " " << slow->val;
        int sum = 0;
        int maxi = 0;
        while(!st.empty() || slow != NULL && slow->next != NULL){
            sum = slow->val + st.top();
            st.pop();
            maxi = max(maxi,sum);
            slow = slow->next;
        }

        return maxi;
    }
};