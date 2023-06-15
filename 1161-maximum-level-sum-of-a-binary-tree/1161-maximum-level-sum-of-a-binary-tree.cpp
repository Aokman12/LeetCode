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
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        int level = 0;
        int maxSum = INT_MIN;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            level++;
            int sum = 0;
            
            for(int i=q.size();i>0;i--){
                TreeNode* temp = q.front();
                q.pop();
                
                sum = sum + temp->val;
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            
            if(maxSum < sum){
                maxSum = sum;
                ans = level;
            }
        }
        
        return ans;
    }
};