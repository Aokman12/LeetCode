class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> temp;
        
        for(int i=0;i<score.size();i++){
            temp.push_back({score[i][k],i});
        }
        
        sort(temp.begin(),temp.end());
        
        vector<vector<int>> ans;
        
        for(int i=score.size()-1;i>=0;i--){
            ans.push_back(score[temp[i][1]]);
        }
        
        return ans;
    }
};