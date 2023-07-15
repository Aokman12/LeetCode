class Solution {
private:
    void solve(int i,string &digits,vector<string>& ans, string &temp,unordered_map<char,string>& mpp){
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }
        
        string str = mpp[digits[i]];
        
        for(int j=0;j<str.size();j++){
            temp.push_back(str[j]);
            solve(i+1,digits,ans,temp,mpp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        vector<string> ans;
        string temp;
        unordered_map<char, string> mpp;
        
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        
        solve(0,digits,ans,temp,mpp);
        
        return ans;
    }
};