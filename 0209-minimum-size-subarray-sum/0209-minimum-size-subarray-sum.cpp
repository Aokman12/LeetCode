class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int e = 0;
        int windowSum = 0;
        int ans = INT_MAX;
        
        while(e<nums.size()){
            windowSum = windowSum + nums[e];
            
            while(windowSum >= target){
                ans = min(ans,e-s+1);
                windowSum = windowSum - nums[s];
                s++;
            }
            e++;
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};