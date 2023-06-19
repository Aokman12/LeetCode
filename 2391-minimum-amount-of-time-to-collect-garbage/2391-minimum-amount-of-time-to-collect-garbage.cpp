class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g=0;
        int m=0;
        int p=0;
        int time=0;
        
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j] == 'G'){
                    g = i;
                }
                else if(garbage[i][j] == 'M'){
                    m = i;
                }
                else{
                    p = i;
                }
                
                time++;
            }
        }
        
        int tot = time;
        time = 0;
        
        for(int i=0;i<travel.size();i++){
            time = time + travel[i];
            if(g == i+1){
                tot = tot + time;
            }
            if(m == i+1){
                tot = tot + time;
            }
            if(p == i+1){
                tot = tot + time;
            }
        }
        
        return tot;
    }
};