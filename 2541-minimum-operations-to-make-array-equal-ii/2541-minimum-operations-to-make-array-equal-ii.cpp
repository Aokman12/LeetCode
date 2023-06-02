class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long pos = 0;
        long long neg = 0;
        if(k==0 && nums1 != nums2){
            return -1;
        }
        if(k==0 && nums1 == nums2){
            return 0;
        }

        for(int i=0;i<nums1.size();i++){
            if(nums1[i] < nums2[i]){
                if((nums2[i]-nums1[i])%k == 0){
                    pos += ((nums2[i]-nums1[i])/k);
                }
                else{
                    return -1;
                }
            }
            else if(nums1[i] > nums2[i]){
                if((nums1[i]-nums2[i])%k == 0){
                    neg += ((nums1[i]-nums2[i])/k);
                }
                else{
                    return -1;
                }
            }
        }

        if(pos != neg){
            return -1;
        }
        return pos;
    }
};