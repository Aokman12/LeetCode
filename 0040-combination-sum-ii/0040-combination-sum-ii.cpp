class Solution {
public:
    void solve(vector<int> &candidates,int target,int start,vector<int> &combination,vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(combination);
            return;
        }
        
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i] == candidates[i-1]){
                continue;
            }
            
            if(candidates[i] <= target){
                combination.push_back(candidates[i]);
                solve(candidates,target-candidates[i],i+1,combination,ans);
                combination.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,combination,ans);
        
        return ans;
    }
};