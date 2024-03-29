bool mySort(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),mySort);
        
        int ans = 0;
        int k = INT_MIN;
        
        for(auto it: intervals){
            int x = it[0];
            int y = it[1];
            
            if(x >= k){
                k=y;
            }
            else{
                ans++;
            }
        }
        
        return ans;
    }
};