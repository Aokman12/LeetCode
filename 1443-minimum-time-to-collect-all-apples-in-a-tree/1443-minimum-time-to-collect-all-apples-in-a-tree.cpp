class Solution {
private:
    int dfs(int node,int parent,vector<vector<int>> &adj,vector<bool> &hasApple){
        int total = 0;
        int subtotal = 0;
        
        for(auto child:adj[node]){
            if(child == parent){
                continue;
            }
            subtotal = dfs(child,node,adj,hasApple);
            if(subtotal || hasApple[child]){
                total = total + subtotal + 2;
            }
        }
        
        return total;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        return dfs(0,-1,adj,hasApple);
    }
};