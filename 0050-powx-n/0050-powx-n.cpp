class Solution {
private:
    double recur(double x,int n){
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        int p = n;
        if(n < 0){
            int p = long(abs(n));
        }
        double ans = recur(x,p/2);
        if(p % 2 == 0){
            return ans * ans;
        }
        else{
            return x * ans * ans;
        }
    }
public:
    double myPow(double x, int n) {
        double ans = recur(x,abs(n));
        if(n<0){
            return 1/ans;
        }
        return ans;
    }
};