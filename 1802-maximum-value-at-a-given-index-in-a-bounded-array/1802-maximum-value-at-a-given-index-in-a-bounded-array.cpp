class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long rsize = n-index-1;
        long long lsize = index;
        
        long long s = 1;
        long long e = maxSum;
        
        long long ans = 0;
        
        while(s<=e){
            long long ls = 0;
            long long rs = 0;
            long long mid = s + (e-s)/2;
            long long m = mid-1;
            long long sum = mid;
            
            if(lsize <= m){
                ls = m*(m+1)/2 - (m-lsize)*(m-lsize+1)/2;
            }
            else{
                ls = m*(m+1)/2 + 1*(lsize-m);
            }
            
            if(rsize <= m){
                rs = m*(m+1)/2 - (m-rsize)*(m-rsize+1)/2;
            }
            else{
                rs = m*(m+1)/2 + 1*(rsize-m);
            }
            
            sum = sum + ls + rs;
            
            if(sum <= maxSum){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        
        return ans;
    }
};