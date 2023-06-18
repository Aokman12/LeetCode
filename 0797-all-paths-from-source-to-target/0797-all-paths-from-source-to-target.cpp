class Solution {
private:
    void solve(vector<vector<int>>& graph,vector<vector<int>> &ans,vector<int> path,int curr){
        path.push_back(curr);
        if(curr == graph.size()-1){
            ans.push_back(path);
        }
        else{
            for(auto it:graph[curr]){
                solve(graph,ans,path,it);
            }
        }
        
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        
        solve(graph,ans,path,0);
        return ans;
    }
};