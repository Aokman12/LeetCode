class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int visited[n][m];
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;   
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }
        
        int t = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            t = max(t,time);
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});   
                    visited[nrow][ncol] = 2;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return t;
    }
};