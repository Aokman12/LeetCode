class Solution {
private:
    void perm(vector<int> &nums,int pos,vector<vector<int>> &ans){
        if(pos >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=pos;i<nums.size();i++){
            swap(nums[i],nums[pos]);
            perm(nums,pos+1,ans);
            swap(nums[i],nums[pos]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        perm(nums,0,ans);
        
        return ans;
    }
};