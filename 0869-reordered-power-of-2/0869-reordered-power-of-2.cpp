class Solution {
public:
    string sorted(int n){
        string str = to_string(n);
        
        sort(str.begin(),str.end());
        
        return str;
    }
    
    bool reorderedPowerOf2(int n) {
        string n_str = sorted(n);
        for(int i=0;i<32;i++){
            if(n_str == sorted(1<<i)){
                return true;
            }
        }
        
        return false;
    }
};