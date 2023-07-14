class Solution {
private:
    void permu(vector<int>& nums,vector<vector<int>> &ans,int pos){
        if(pos >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> sett;
        
        for(int i=pos;i<nums.size();i++){
            if(sett.find(nums[i]) != sett.end()){
                continue;
            }
            sett.insert(nums[i]);
            swap(nums[i],nums[pos]);
            permu(nums,ans,pos+1);
            swap(nums[i],nums[pos]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        permu(nums,ans,0);
        
        return ans;
    }
};