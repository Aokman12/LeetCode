class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int i=0;
        int j=s.size()-1;
        
        bool one = false;
        bool two = false;
        bool seen [256];
        memset(seen,false,sizeof(seen));
        bool equal = false;
        if(s==goal){
            equal = true;
        }
        
        if(s.size() == 1){
            return false;
        }
        while(i<j){
            if(one == false && s[i] == goal[i]){
                i++;
            }
            else{
                one = true;
            }
            if(two == false && s[j] == goal[j]){
                j--;
            }
            else{
                two = true;
            }
            if(one && two){
                break;
            }
        }
        
        if(equal){
            for(int k=0;k<s.size();k++){
                char c = s[k];
                if(seen[c]){
                    return true;
                }
                seen[c] = true;
            }
        }
        
        swap(s[i],s[j]);
        return s==goal;
    }
};