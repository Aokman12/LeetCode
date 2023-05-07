class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sett;
        int i = 0;
        int j = 0;
        int size = 0; 
        
        while(j<s.length()){
            while(sett.find(s[j]) != sett.end()){
                sett.erase(s[i]);
                i++;
            }
            size = max(size,j-i+1);
            sett.insert(s[j]);
            j++;
        }
        return size;
    }
};