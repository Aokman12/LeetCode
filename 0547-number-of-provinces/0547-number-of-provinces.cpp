class Solution {
public:
    void solve(int i,vector<vector<int>> &isConnected,vector<bool> &visited){
        visited[i] = true;
        
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j] && !visited[j]){
                solve(j,isConnected,visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int prov = 0;
        vector<bool> visited(n);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                prov++;
                solve(i,isConnected,visited);
            }
        }
        
        return prov;
    }
};