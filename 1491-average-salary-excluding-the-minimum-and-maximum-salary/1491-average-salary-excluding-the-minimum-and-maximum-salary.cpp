class Solution {
public:
    double average(vector<int>& salary) {
        
        int maxi = *max_element(salary.begin(),salary.end());
        int mini = *min_element(salary.begin(),salary.end());
        
        int sum = 0;
        
        for(int i=0;i<salary.size();i++){
            sum = sum + salary[i];
        }
        
        double ans = sum - maxi - mini;
        
        ans = ans / (salary.size()-2);
        
        return ans;
    }
};