class Solution {
public:
    int minNumberOfHours(int ie, int xp, vector<int>& energy, vector<int>& experience) {
        int hours = 0;
        int sum  = 0;
        
        for(int i=0;i<energy.size();i++){
            sum += energy[i];
            
            if(experience[i] >= xp){
                hours += experience[i] - xp + 1;
                xp += experience[i] - xp + 1;
            }
            xp += experience[i];
        }
        if(ie <= sum){
            hours += sum - ie + 1;    
        }
        return hours;
    }
};