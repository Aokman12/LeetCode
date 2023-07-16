class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int pro = 1;
        int ans = 0;
        int start = 0;
        int end = 0;
        
        while(end<nums.size()){
            pro *= nums[end];
            while(pro >= k){
                pro /= nums[start];
                start++;
            }
            ans += end-start + 1;
            end++;
        }
        
        return ans;
    }
};