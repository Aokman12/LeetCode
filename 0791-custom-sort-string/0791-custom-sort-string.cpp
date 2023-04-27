class Solution {
public:
    string customSortString(string order, string s) {
        int maxChar[26] = {0};
        
        for(int i=0;i<s.length();i++){
            maxChar[s[i]-'a']++;
        }
        
        int index = 0;
        
        for(int i=0;i<order.length();i++){
            for(int j=0;j<maxChar[order[i]-'a'];j++){
                s[index++] = order[i];
            }
            maxChar[order[i]-'a'] = 0;
        }
        
        for(int i = 0;i<26;i++){
            for(int j=0;j<maxChar[i];j++){
                s[index++] = 'a' + i;
            }
        }
        
        return s;
    }
};