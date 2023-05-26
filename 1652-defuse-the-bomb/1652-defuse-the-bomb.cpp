class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int i,j,m,count;
        for(i=0;i<code.size();i++){
            count = 0;
            j=i;
            m = abs(k);
            while(m--){
                if(k<0){
                    j = j-1;
                    if(j<0){
                        j = j+code.size();
                    }
                    count = count + code[j];
                }
                else if(k>0){
                    j = j+1;
                    if(j>=code.size()){
                        j = j-code.size();
                    }
                    count = count + code[j];
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};