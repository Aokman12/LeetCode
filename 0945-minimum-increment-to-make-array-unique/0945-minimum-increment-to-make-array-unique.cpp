class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int size = nums.size() + maxi;
        vector<int> count(size);
        
        for(auto it:nums){
            count[it]++;
        }
        
        int moves = 0;
        int taken = 0;
        
        for(int i=0;i<size;i++){
            if(count[i] >= 2){
                taken += count[i] - 1;
                moves -= i * (count[i] - 1);
            }
            else if(taken > 0 && count[i] == 0){
                taken--;
                moves += i;
            }
        }
        
        return moves;
    }
};