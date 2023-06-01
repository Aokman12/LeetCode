class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sett(nums.begin(),nums.end());
        int maxi = 0;
        
        for(auto &i:sett){
            if(!sett.count(i-1)){
                int length = 1;
                while(sett.count(i+length)){
                    length++;
                }
                maxi = max(maxi,length);
            }
        }
        return maxi;
    }
};