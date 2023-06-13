class Solution {
private: 
    static bool mysort(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        sort(courses.begin(),courses.end(),mysort);
        int time = 0;
        for(auto c:courses){
            if(time + c[0] <= c[1]){
                pq.push(c[0]);
                time = time + c[0];
            }
            else if(!pq.empty() && pq.top() > c[0]){
                time = time + c[0] - pq.top();
                pq.pop();
                pq.push(c[0]);
            }
        }
        
        return pq.size();
    }
};