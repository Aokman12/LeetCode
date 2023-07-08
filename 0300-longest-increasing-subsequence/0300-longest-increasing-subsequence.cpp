class Solution {
    int dp[2515];
    
    int solve(vector<int> &nums,int i){
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 1;
        
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                ans = max(ans,solve(nums,j)+1);
            }
        }
        
        return dp[i] = ans;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        
        for(int i=0;i<n;i++){
            ans = max(ans,solve(nums,i));
        }
        
        return ans;
    }
};