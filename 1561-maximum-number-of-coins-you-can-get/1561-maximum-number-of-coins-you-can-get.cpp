class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int i=0;
        int k=piles.size()-1;
        int j=k-1;
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        
        while(i<j){
            sum1 += piles[i];
            sum2 += piles[j];
            sum3 += piles[k];
            i++;
            j=j-2;
            k=k-2;
        }
        
        return sum2;
    }
};