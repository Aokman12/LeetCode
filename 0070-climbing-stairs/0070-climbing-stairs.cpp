class Solution {
public:
    int climbStairs(int n) {
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        
        int onestep = 2;
        int twostep = 1;
        int allWays = 0;
        
        for(int i=2;i<n;i++){
            allWays = onestep + twostep;
            twostep = onestep;
            onestep = allWays;
        }
        
        return allWays;
    }
};