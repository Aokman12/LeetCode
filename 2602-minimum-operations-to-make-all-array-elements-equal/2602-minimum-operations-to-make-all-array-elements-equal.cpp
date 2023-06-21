class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> prefix{0};
        vector<long long> ans;
        
        sort(nums.begin(),nums.end());
        
        for(auto n:nums){
            prefix.push_back(prefix.back()+n);
        }
        
        for(long long q:queries){
            int i=upper_bound(nums.begin(),nums.end(),q)-nums.begin();
            ans.push_back(q*i-prefix[i] + (prefix.back()-prefix[i])-q*(nums.size()-i));
        }
        
        return ans;
    }
};