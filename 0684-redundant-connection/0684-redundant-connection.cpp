class Solution {
private:
    int findParent(int n,vector<int> &parent){
        if(n == parent[n]){
            return n;
        }
        
        return findParent(parent[n],parent);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1,0);
        
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
        }
        
        vector<int> ans;
        
        for(auto V:edges){
            int n1 = V[0];
            int n2 = V[1];
            int p1 = findParent(n1,parent);
            int p2 = findParent(n2,parent);
            
            if(p1 == p2){
                ans = V;
            }
            
            parent[p1] = p2;
        }
        
        return ans;
    }
};