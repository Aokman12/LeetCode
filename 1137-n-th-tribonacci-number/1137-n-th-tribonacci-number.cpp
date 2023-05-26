class Solution {
public:
    int trib(int n,vector<int> &dp){
        if(n<=1){
            return n;
        }
        if(n==2){
            return 1;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = trib(n-1,dp) + trib(n-2,dp) + trib(n-3,dp);
        return dp[n];
    }
    
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        
        return trib(n,dp);
    }
};