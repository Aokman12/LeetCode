class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int coll = 0;
        
        for(int i=0;i<directions.length();i++){
            if(st.empty()){
                st.push(directions[i]);
            }
            else if(st.top() == 'R' && directions[i] == 'L'){
                st.pop();
                directions[i] = 'S';
                i--;
                coll += 2;
            }
            
            else if(st.top() == 'S' && directions[i] == 'L'){
                coll++;
            }
            
            else if(st.top() == 'R' && directions[i] == 'S'){
                st.pop();
                directions[i] = 'S';
                i--;
                coll++;
            }
            
            else{
                st.push(directions[i]);
            }
        }
        
        return coll;
    }
};