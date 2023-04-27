class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        int s=0;
        int e=nums.size()-1;
        int mid;
        int x;
        
        while(s<e){
            mid = s + (e-s)/2;
            x = (mid%2 == 0) ? (mid+1) : (mid-1);
            if(nums[mid] == nums[x]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        return nums[s];
        
        // int x=0;
        // for(int i=0;i<nums.size();i++){
        //     x = x ^ nums[i];
        // }
        // return x;
    }
};