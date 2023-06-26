class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        
        int i=0;
        int j=costs.size()-1;
        long long ans = 0;
        
        while(k--){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i++]);
            }
            
            while(pq2.size()<candidates && i<=j){
                pq2.push(costs[j--]);
            }
            
            int a = pq1.size() ? pq1.top():INT_MAX;
            int b = pq2.size() ? pq2.top():INT_MAX;
            
            ans += (a<=b?a:b);
            a<=b? pq1.pop():pq2.pop();
        }
        
        return ans;
    }
};