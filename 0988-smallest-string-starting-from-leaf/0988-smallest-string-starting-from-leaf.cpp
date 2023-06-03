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
    string ans = "";
public:
    void solve(TreeNode* root,string &s){
        if(root == NULL){
            return ;
        }
        
        s.push_back('a' + root->val);
        
        if(root->left == NULL && root->right == NULL){
            string temp = s;
            reverse(temp.begin(),temp.end());
            if(ans.empty() || temp<ans){
                ans = temp;
            }
        }
        
        solve(root->left,s);
        solve(root->right,s);
        s.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        solve(root,s);
        return ans;
    }
};