class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string,greater<int>> mp;
        
        for(int i=0;i<names.size();i++){
            mp[heights[i]] = names[i];
        }
        
        int j=0;
        
        for(auto i: mp){
            names[j++] = i.second;
        }
        
        return names;
    }
};