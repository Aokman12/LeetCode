class Solution {
public:
    int findMaxi(vector<int>& satisfaction,vector<vector<int>>& dp,int index,int time){
        if(index == satisfaction.size()){
            return 0;
        }

        if(dp[index][time] != -1){
            return dp[index][time];
        }

        return dp[index][time] = max(satisfaction[index]*time + findMaxi(satisfaction,dp,index+1,time+1),findMaxi(satisfaction,dp,index+1,time));
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());

        vector<vector<int>> dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));

        return findMaxi(satisfaction,dp,0,1);
    }
};