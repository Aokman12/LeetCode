class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans;
        
        sort(nums.begin(),nums.end());
        
        int miss = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == miss){
                miss++;
                continue;
            }
            ans = miss;
            break;
        }
        
        return ans;
    }
};