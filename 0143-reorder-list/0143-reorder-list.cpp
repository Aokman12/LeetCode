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
    void reorderList(ListNode* head) {
        vector<ListNode*> l2;
        ListNode* temp = head;

        while(temp != NULL){
            l2.push_back(temp);
            temp = temp->next;
        }

        int i=0;
        int j=l2.size()-1;

        while(i<j){
            l2[i]->next = l2[j];
            i++;

            if(i==j){
                break;
            }
            l2[j]->next = l2[i];
            j--;
        }

        l2[i]->next = NULL;
    }
};