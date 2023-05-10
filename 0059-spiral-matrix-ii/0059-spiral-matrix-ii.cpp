class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {       
        int cnt = 1;
        vector<vector<int>> ans(n,vector<int>(n));
        
        for(int row = 0; row < (n+1)/2; row++){
            for(int i = row;i<n-row;i++){
                ans[row][i] = cnt++;
            }
            
            for(int i = row+1;i<n-row;i++){
                ans[i][n-row-1] = cnt++;
            }
            
            for(int i = n-row-2;i>=row;i--){
                ans[n-row-1][i] = cnt++;
            }
            
            for(int i = n-row-2;i>row;i--){
                ans[i][row] = cnt++;
            }
        }
        return ans;
    }
};