//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
bool isSafe(int newx,int newy,vector<vector<bool>> &visited,vector<vector<int>> &m,int n){
    if((newx >= 0 && newy < n) && (newy >= 0 && newx < n) &&
        visited[newx][newy] != 1 && m[newx][newy] == 1){
            return true;
        }
        else{
            return false;
        }
}

void solve(int x,int y,vector<vector<int>> &m,int n,vector<string> &ans,
            vector<vector<bool>> &visited,string path){
    
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    //down
    if(isSafe(x+1,y,visited,m,n)){
        visited[x][y] = 1;
        solve(x+1,y,m,n,ans,visited,path+'D');
        visited[x][y] = 0;
    }

    if(isSafe(x,y-1,visited,m,n)){
        visited[x][y] = 1;
        solve(x,y-1,m,n,ans,visited,path + 'L');
        visited[x][y] = 0;
    }

    if(isSafe(x,y+1,visited,m,n)){
        visited[x][y] = 1;
        solve(x,y+1,m,n,ans,visited,path + 'R');
        visited[x][y] = 0;
    }

    if(isSafe(x-1,y,visited,m,n)){
        visited[x][y] = 1;
        solve(x-1,y,m,n,ans,visited,path + 'U');
        visited[x][y] = 0;
    }
}
        
class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool> (n,0));
    string path = "";

    if(m[0][0] == 0){
        return ans;
    }

    solve(0,0,m,n,ans,visited,path);
    return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends