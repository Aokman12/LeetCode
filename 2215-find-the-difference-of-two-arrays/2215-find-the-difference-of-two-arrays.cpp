class Solution {
public:
    vector<int> element1(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> only1;
        
        for(int i=0;i<nums1.size();i++){
            bool inNums2 = false;
            for(int j=0;j<nums2.size();j++){
                if(nums2[j] == nums1[i]){
                    inNums2 = true;
                    break;
                }
            }

            if(!inNums2){
                only1.insert(nums1[i]);
            }
        }

        return vector<int> (only1.begin(),only1.end());
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {element1(nums1,nums2),element1(nums2,nums1)};
    }
};