class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int> st;
        int n = v.size();
        for(int i=0;i<n;i++){
            if(v[i] > 0 || st.empty()){
                st.push(v[i]);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(v[i])){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(v[i])){
                    st.pop();
                }
                else{
                    if(st.empty() || st.top() < 0){
                        st.push(v[i]);
                    }
                }
            }
        }
        vector<int> res(st.size());
        for(int i = (int)st.size() - 1;i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
