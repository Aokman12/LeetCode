class Solution {
private:
    void recur(vector<int>& nums,vector<vector<int>> &ans,vector<int> temp,int ind){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        recur(nums,ans,temp,ind+1);
        temp.push_back(nums[ind]);
        recur(nums,ans,temp,ind+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        recur(nums,ans,temp,0);
        
        return ans;
    }
};