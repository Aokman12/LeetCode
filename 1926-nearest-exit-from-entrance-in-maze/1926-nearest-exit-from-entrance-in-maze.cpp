class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};
                                
        dis[entrance[0]][entrance[1]] = 0;
        queue<pair<pair<int,int>,int>> q;
        q.push({{entrance[0],entrance[1]},0});
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            if(row==0 || col==0 || row==m-1 || col==n-1){
                if(row != entrance[0] || col != entrance[1]){
                    return steps;
                }
            }
            
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 
                
                if(nrow<0 || nrow>m-1 || ncol<0 || ncol>n-1){
                    continue;
                }
                
                if(maze[nrow][ncol] == '.'){
                    if(steps+1 <dis[nrow][ncol]){
                        dis[nrow][ncol] = steps+1;
                        q.push({{nrow,ncol},steps+1});
                    }
                }
            }
        }
        
        return -1;
    }
};