class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        
        int s=0;
        int e=tokens.size()-1;
        int score=0;
        int ans=0;
        
        while(s<=e && (power>=tokens[s] || score>0)){
            while(s<=e && power>= tokens[s]){
                power -= tokens[s++];
                score++;
            }
            
            ans = max(ans,score);
            
            if(s<=e && score > 0){
                power += tokens[e--];
                score--;
            }
        }
        
        return ans;
    }
};