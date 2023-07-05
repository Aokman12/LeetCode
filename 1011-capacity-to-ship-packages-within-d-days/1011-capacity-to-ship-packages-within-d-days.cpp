class Solution {
private:
    bool isPossible(vector<int>& weights,int c,int days){
        int daysReq = 1;
        int currLoad = 0;
        
        for(auto it: weights){
            currLoad += it;
            if(currLoad > c){
                daysReq++;
                currLoad = it;
            }
        }
        
        return daysReq <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = *max_element(weights.begin(),weights.end());
        
        int it = 0;
        int total = 0;
        
        for(auto it:weights){
            total += it;
        }
        
        while(maxi < total){
            int mid = (maxi + total) / 2;
            
            if(isPossible(weights,mid,days)){
                total = mid;
            }
            else{
                maxi = mid+1;
            }
        }
        
        return maxi;
    }
};