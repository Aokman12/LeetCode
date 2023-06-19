class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        bool up = false;
        bool down = false;
        int end = 0;
        while(end+1 < n){
            if(arr[end] < arr[end+1]){
                int start = end;
                
                while(end+1 < n && arr[end] < arr[end+1]){
                    up = true;
                    end++;
                }
                
                while(end+1 < n && arr[end] > arr[end+1]){
                    down = true;
                    end++;
                }
                
                if(up && down){
                    ans = max(ans,end - start + 1);
                }
                
                up = false;
                down = false;
            }
            else{
                end++;
            }
        }
        
        return ans;
    }
};