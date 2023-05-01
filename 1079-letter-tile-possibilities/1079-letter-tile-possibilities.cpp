class Solution {
public:
    void solve(string tiles,int take,int &count){
        count++;
        
        for(int i=take;i<tiles.length();i++){
            if(i != take && tiles[i] == tiles[take]){
                continue;
            }
            swap(tiles[i],tiles[take]);
            solve(tiles,take+1,count);
        }
    }
    
    int numTilePossibilities(string tiles) {
        int count = -1;
        sort(tiles.begin(),tiles.end());
        solve(tiles,0,count);
        return count;
    }
};