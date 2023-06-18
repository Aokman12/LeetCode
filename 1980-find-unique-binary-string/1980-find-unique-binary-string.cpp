class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = nums[0];
        for(int i=0;i<nums[0].size();i++){
            ans[i] = nums[i][i] == '0' ? '1': '0';
        }
        
        return ans;
    }
};