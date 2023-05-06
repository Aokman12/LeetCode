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
public:
    bool solve(TreeNode* root,long left,long right){
        if(root == NULL){
            return true;
        }
        
        if(root->val < right && root->val > left){
            bool leftAns = solve(root->left,left,root->val);
            bool rightAns = solve(root->right,root->val,right);
            
            if(leftAns && rightAns){
                return true;
            }
        }
        
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        return solve(root,LONG_MIN,LONG_MAX);
    }
};