class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0 || 
           visited[i][j]){
            return 0;
        }
        
        visited[i][j] = true;
        
        return grid[i][j] + solve(grid,i+1,j,visited) + solve(grid,i-1,j,visited) +
            solve(grid,i,j+1,visited) + solve(grid,i,j-1,visited);
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        vector visited(grid.size(),vector<bool>(grid[0].size()));
        int ans = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans = max(ans,solve(grid,i,j,visited));
            }
        }
        
        return ans;
    }
};