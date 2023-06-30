class Solution {
private:
    void solve(int row,int col,int m,int n,vector<vector<int>>& board,vector<vector<int>> &ans){
        int countOne = 0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nrow = row + i;
                int ncol = col + j;
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    if(board[nrow][ncol] == 1){
                        countOne++;
                    }
                }
            }
        }
        
        if(board[row][col] == 0){
            if(countOne == 3){
                ans[row][col] = 1;
            }
        }
        
        else if(board[row][col] == 1){
            if(countOne < 3){
                ans[row][col] = 0;
            }
            else if(countOne == 3 || countOne == 4){
                ans[row][col] = 1;
            }
            else if(countOne > 4){
                ans[row][col] = 0;
            }
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                solve(row,col,m,n,board,ans);
            }
        }
        board = ans;
        
        
    }
};