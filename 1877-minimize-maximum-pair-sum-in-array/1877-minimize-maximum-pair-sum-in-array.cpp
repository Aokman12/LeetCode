class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        
        sort(nums.begin(),nums.end());
        int maxi = 0;
        
        while(i<j){
            maxi = max(maxi,(nums[i++]+nums[j--]));
        }
        
        return maxi;
    }
};