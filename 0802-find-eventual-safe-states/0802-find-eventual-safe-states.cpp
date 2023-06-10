class Solution {
private:
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &visited,vector<int> &pathVis,vector<int> &check){
        visited[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto it: graph[node]){
            if(!visited[it]){
                if(dfs(it,graph,visited,pathVis,check) == true){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        
        vector<int> visited (V,0);
        vector<int> pathVis (V,0);
        vector<int> check (V,0);
        
        vector<int> safenodes;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,graph,visited,pathVis,check);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i] == 1){
                safenodes.push_back(i);
            }
        }
        
        return safenodes;
    }
};