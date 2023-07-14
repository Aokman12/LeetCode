class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans = 1;
        
        for(auto it: arr){
            int noTake = dp.count(it-difference) ? dp[it-difference] : 0;
            dp[it] = noTake + 1;
            ans = max(ans,dp[it]);
        }
        
        return ans;
    }
};