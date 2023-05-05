class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    
    int maxVowels(string s, int k) {
        int maxi = 0;
        int count = 0;
        
        for(int i=0;i<s.length();i++){
            if(i >= k && isVowel(s[i-k])){
                count--;
            }
            
            if(isVowel(s[i])){
                count++;
            }
            
            maxi = max(maxi,count);
        }
        
        return maxi;
    }
};