class Solution {
public:
    bool isUgly(int n) {
        if(n<=0){
            return false;
        }
        for(auto i: {2,3,5}){
            n = divide(n,i);
        }
        return n==1;
    }
    
    int divide(int n,int i){
        while(n%i==0){
            n = n/i;
        }
        return n;
    }
};