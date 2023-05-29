class Solution {
public:
    void solve(vector<int> &nums,vector<bool> &used,vector<int> &permu,vector<vector<int>> &ans){
        if(permu.size() == nums.size()){
            ans.push_back(permu);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(used[i] || i>0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            used[i] = true;
            permu.push_back(nums[i]);
            solve(nums,used,permu,ans);
            permu.pop_back();
            used[i] = false;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> permu;
        vector<bool> used(nums.size(),false);
        
        sort(nums.begin(),nums.end());
        
        solve(nums,used,permu,ans);
        
        return ans;
    }
};