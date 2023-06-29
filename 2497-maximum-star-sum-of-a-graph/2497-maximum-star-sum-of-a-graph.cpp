class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        int sum = INT_MIN;
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<n;i++){
            priority_queue<int,vector<int>,greater<int>> pq;
            
            int tempSum = vals[i];
            
            for(int it: adj[i]){
                pq.push(vals[it]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
            
            while(!pq.empty()){
                if(pq.top() > 0){
                    tempSum += pq.top();
                }
                pq.pop();
            }
            
            sum = max(sum,tempSum);
        }
        
        return sum;
    }
};