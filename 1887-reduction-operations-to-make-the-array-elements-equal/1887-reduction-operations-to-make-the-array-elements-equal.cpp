class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0;
        int fre = 0;
        map<int,int> count;
        
        for(auto it: nums){
            count[it]++;
        }
        
        for(auto i = count.end();i!= count.begin();i--){
            ans += i->second + fre;
            fre += i->second;
        }
        
        return ans;
    }
};