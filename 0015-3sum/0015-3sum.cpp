class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(auto i=0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int s = i+1;
            int e = nums.size()-1;
            
            while(s<e){
                int sum = nums[i]+nums[s]+nums[e];
                if(sum>0){
                    e--;
                }
                else if(sum<0){
                    s++;
                }
                else{
                    ans.push_back(vector<int> {nums[i],nums[s],nums[e]});
                    while(s<e && nums[s] == nums[s+1]){
                        s++;
                    }
                    while(s<e && nums[e] == nums[e-1]){
                        e--;
                    }
                    s++;
                    e--;
                }
            }
        }
        return ans;
    }
};