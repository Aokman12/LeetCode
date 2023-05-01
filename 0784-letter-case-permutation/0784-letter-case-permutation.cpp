class Solution {
public:
    void permu(string &s,vector<string> &ans,string output,int i){
        if(i >= s.length()){
            ans.push_back(output);
            return;
        }
        
        if(s[i] >= '0' && s[i] <= '9'){
            output.push_back(s[i]);
            permu(s,ans,output,i+1);
        }
        else{
            output.push_back(s[i]);
            permu(s,ans,output,i+1);
            output.pop_back();
            
            if(s[i] >= 'A' && s[i] <= 'Z'){
                output.push_back(s[i] - 'A' + 'a');
            }
            else{
                output.push_back(s[i] + 'A' - 'a');
            }
            permu(s,ans,output,i+1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        
        permu(s,ans,"",0);
        
        return ans;
    }
};