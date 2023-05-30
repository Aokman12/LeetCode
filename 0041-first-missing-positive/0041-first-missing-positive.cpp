class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int i=0;
        unordered_map<int,int> count;
        
        for(i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        
        for(i=1;i<=maxi;i++){
            if(count.find(i) == count.end()){
                return i;
            }
        }
        if(maxi < 0){
            return 1;
        }
        return maxi+1;
    }
};