class Solution {
public:
    int find(vector<int> &piles,int hour){
        int sum = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%hour == 0){
                sum += piles[i]/hour;
            }
            else{
                sum += (piles[i]/hour) +1;
            }
        }

        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(),piles.end());
        
        while(s<e){
            int mid = s + (e-s)/2;
            int sum = find(piles,mid);

            if(sum <= h){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};