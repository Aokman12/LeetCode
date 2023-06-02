class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mpp;
        
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]] = i;
        }
        
        for(int i=0;i<operations.size();i++){
            int ind = mpp[operations[i][0]];
            nums[ind] = operations[i][1];
            mpp[nums[ind]] = ind;
        }
        
        return nums;
    }
};