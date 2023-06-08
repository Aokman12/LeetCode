class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int path = 1;
        
        if(grid[0][0] != 0){
            return -1;
        }
        if(grid[n-1][n-1] != 0){
            return -1;
        }
        
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(row == n-1 && col == n-1){
                return grid[row][col];
            }
            
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 0){
                        q.push({nrow,ncol});
                        grid[nrow][ncol] = grid[row][col] + 1;
                    }
                }
            }
        }
        return -1;
    }
};