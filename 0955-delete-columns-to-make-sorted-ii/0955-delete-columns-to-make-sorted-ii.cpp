class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        unordered_set<int> del;
        
        for(int i=1;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                if(del.count(j)>0 || strs[i-1][j] == strs[i][j]){
                    continue;
                }
                if(strs[i-1][j] > strs[i][j]){
                    del.insert(j);
                    i=0;
                }
                break;
            }   
        }
        return del.size();
    }
};