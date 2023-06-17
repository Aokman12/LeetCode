class Solution {
    int ans = 0;
    int sum = 0;
private:
    int dfs(vector<vector<int>>& grid,int row,int col,int m,int n){
        grid[row][col] = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        sum++;
        
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                dfs(grid,nrow,ncol,m,n);
            }
        }
        
        return sum;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    sum=0;
                    ans = max(ans,dfs(grid,i,j,m,n));
                }
            }
        }
        
        return ans;
    }
};