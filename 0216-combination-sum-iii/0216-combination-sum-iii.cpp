class Solution {
private:
    void solve(vector<int> &nums,int k,int n,vector<vector<int>> &ans,
        vector<int> temp,int ind){
        if(temp.size() == k && n == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(nums,k,n-nums[i],ans,temp,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(nums,k,n,ans,temp,0);
        
        return ans;
    }
};