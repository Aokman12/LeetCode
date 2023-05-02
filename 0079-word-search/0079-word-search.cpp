class Solution {
public:
    bool solve(int index,int x,int y,vector<vector<char>>& board, string &word){
        if(index == word.size()){
            return true;
        }
        
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == '*'){
            return false;
        }
        
        if(board[x][y] != word[index]){
            return false;
        }
        
        char temp = board[x][y];
        board[x][y] = '*';
        
        if(solve(index+1,x-1,y,board,word) || solve(index+1,x+1,y,board,word) || solve(index+1,x,y-1,board,word) || solve(index+1,x,y+1,board,word)){
            return true;
        }
        
        board[x][y] = temp;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(0,i,j,board,word)){
                    return true;
                }
            }
        }
        return false; 
    }
};