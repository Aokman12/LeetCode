class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1){
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size();i++){
            for(int j=0;j<intervals[0].size();j++){
               cout<<intervals[i][j]<<","; 
            }
            cout<<endl;
        }
        
        vector<vector<int>> ans;
        
        int i=0;
        while(i<intervals.size()-1){
            if(intervals[i][1] >= intervals[i+1][0]){
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1],intervals[i+1][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
            i++;
        }
        ans.push_back(intervals[i]);
        
        return ans;
    }
};