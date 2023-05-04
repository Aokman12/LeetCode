class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr;
        queue<int> qd;

        for(int i=0;i<senate.length();i++){
            if(senate[i] == 'R'){
                qr.push(i);
            }
            else{
                qd.push(i);
            }
        }
        
        int n = senate.length();
        while(!qr.empty() && !qd.empty()){
            int i = qr.front();
            int j = qd.front();

            qr.pop();
            qd.pop();

            if(i<j){
                qr.push(i+n);
            }
            else{
                qd.push(j+n);
            }
        }

        if(qd.size() > qr.size()){
            return "Dire";
        }
        else{
            return "Radiant";
        }
    }
};