/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root,vector<int> &values){
        if(root == NULL){
            return;
        }

        values.push_back(root->val);
        solve(root->left,values);
        solve(root->right,values); 
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        solve(root,values);

        sort(values.begin(),values.end());
        int mini = INT_MAX;

        for(int i=1;i<values.size();i++){
            mini = min(mini,values[i]-values[i-1]);
        }

        return mini;
    }
};