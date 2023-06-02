class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long pro = 1;
        int neg = -1;
        int bigNeg = INT_MIN;
        int largest = INT_MIN;
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0){
                pro = pro * nums[i];
            }
            else if(nums[i] < 0){
                pro = pro * nums[i];
                bigNeg = max(bigNeg,nums[i]);
                count++;
            }
            largest = max(largest,nums[i]);
        }
        
        if(largest == 0 && count<2){
            return 0;
        }
        if(largest < 0 && count == 1){
            return bigNeg;
        }
        if(pro > 0){
            return pro;
        }
        return pro/bigNeg;
    }
};