class Solution {
public:
    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &visited){
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
        
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            for(int i=0;i<dir.size();i++){
                int nrow = row + dir[i][0];
                int ncol = col + dir[i][1];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && grid[nrow][ncol] == '1'                       && !visited[nrow][ncol]){
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count = 0;
        
        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(grid[row][col] == '1' && !visited[row][col]){
                    count++;
                    bfs(row,col,grid,visited);
                }
            }
        }
        
        return count;
    }
};