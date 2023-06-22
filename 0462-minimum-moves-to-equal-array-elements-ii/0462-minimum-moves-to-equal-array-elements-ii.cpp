class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        int target = nums[n/2];
        
        for(int i=0;i<n;i++){
            ans = ans + abs(nums[i]-target);
        }
        
        return ans;
    }
};