class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int ans = 0;
        bool flag = false;
        
        while(j<nums.size()){
            if(flag && nums[j] == 0){
                ans = max(ans,j-i-1);
                if(nums[i] == 0){
                    i++;
                }
                else if(nums[i] == 1){
                    while(i<nums.size() && nums[i] != 0){
                        i++;
                    }
                    i++;
                }
                
            }
            if(nums[j] == 1){
                j++;
            }
            else{
                flag = true;
                j++;
            }
        }
        ans = max(ans,j-i-1);
        return ans;
    }
};