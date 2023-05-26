class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        bool alice = true;
        int s = 0;
        int e = piles.size()-1;
        int sum1 = 0;
        int sum2 = 0;
        
        for(int i=0;i<piles.size();i++){
            if(alice){
                if(piles[s] > piles[e]){
                    sum1 = sum1 + piles[s];
                    s++;
                }
                else{
                    sum1 = sum1 + piles[e];
                    e--;
                }
            }
            else{
                if(piles[s] < piles[e]){
                    sum2 = sum2 + piles[s];
                    s++;
                }
                else{
                    sum2 = sum2 + piles[e];
                    e--;
                }
            }
            alice = !alice;
        }
        
        if(sum1 > sum2){
            return true;
        }
        else{
            return false;
        }
    }
};