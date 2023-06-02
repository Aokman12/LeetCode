class Solution {
public:
    int p=1;
    bool checkPowersOfThree(int n,int p=1) {
        if(n==0){
            return true;
        }
        if(n<p){
            return false;
        }
        return checkPowersOfThree(n,p*3) || checkPowersOfThree(n-p,p*3); 
    }
};