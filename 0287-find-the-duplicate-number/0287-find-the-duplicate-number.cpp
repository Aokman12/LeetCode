class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1){
                return nums[i];
            }
        }
        
        // for(auto i:mp){
        //     if(i.second > 1){
        //         return i.first;
        //     }
        // }
        
        return nums[0];
    }
};