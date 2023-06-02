class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size(),0);
        unordered_map<int,int> mpp;
        
        for(int i=0;i<A.size();i++){
            mpp[B[i]]++;
            int com = 0;
            for(int j=0;j<=i;j++){
                if(mpp.count(A[j])){
                    com++;
                }
            }
            ans[i] = com;
        }
        
        return ans;
    }
};