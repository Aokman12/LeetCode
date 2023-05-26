class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char,int> count;
        int n = s.size();
        
        for(auto it:s){
            count[it]++;
        }
        
        if(count['a']<k || count['b']<k || count['c']<k){
           return -1; 
        }
        
        int i = n-1;
        int j = n-1;
        int timer = n;
        
        while(i>=0){
            count[s[i]]--;
            while(count['a']<k || count['b']<k || count['c']<k){
                count[s[j]]++;
                j--;
            }
            timer = min(timer,i+n-1-j);
            i--;
        }
        return timer;
    }
};