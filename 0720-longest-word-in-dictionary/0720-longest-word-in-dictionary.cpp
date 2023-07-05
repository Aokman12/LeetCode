class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        int len = 0;
        
        for(auto it: words){
            string st = "";
            bool b = false;
            
            for(int i=0;i<it.length();i++){
                st += it[i];
                if(find(words.begin(),words.end(),st) == words.end()){
                    b = true;
                    break;
                }
            }
            
            if(!b){
                if(ans.length() == st.length()){
                    ans = min(ans,st);
                    len = ans.length();
                }
                else{
                    if(st.length() > ans.length()){
                        ans = st;
                        len = ans.length();
                    }
                }
            }
        }
        
        return ans;
    }
};