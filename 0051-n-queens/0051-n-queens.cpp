class Solution {
public:
    bool isSafe(int row,int col,vector<string> arr){
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[row][i]!='.'){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i][col]!='.'){
                return false;
            }
        }

        int i=row;
        int j=col;
        while(i>=0 && j>=0)
        {
            if(arr[i][j]!='.'){
                return false;
            }
            i--;
            j--;
        }
        i=row;
        j=col;
        while(i>=0 && j<n)
        {
            if(arr[i][j]!='.'){
                return false;
            }
            i--;
            j++;
        }

        return true;
    }
    
    void solve(int index,int count,int n,vector<string> arr,vector<vector<string>> &ans){
        if(count==n)
        {
            ans.push_back(arr);
            return;
        }
        if(index>=n)
        {
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(index,i,arr))
            {
                arr[index][i] = 'Q';
                solve(index+1,count+1,n,arr,ans);
                arr[index][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> arr;
        string curr;
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            curr+='.';
        }
        for(int j=0;j<n;j++){
            arr.push_back(curr);
        }

        solve(0,0,n,arr,ans);

        return ans;
    }
};