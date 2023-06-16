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
    void solve(TreeNode* root,int val){
        if(root == NULL){
            return ;
        }
        if(val < root->val && !root->left){
            root->left = new TreeNode(val);
            return;
        }
        else if(val < root->val){
            solve(root->left,val);
        }
        if(val > root->val && !root->right){
            root->right = new TreeNode(val);
            return;
        }
        else if(val>root->val){
            solve(root->right,val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        solve(root,val);
        if(root == NULL){
            root = new TreeNode(val);
        }
        return root;
    }
};