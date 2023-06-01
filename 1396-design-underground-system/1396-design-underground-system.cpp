class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> mpp;
    unordered_map<string,pair<double,int>> route;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mpp[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int startTime = mpp[id].second;
        string path = mpp[id].first + "_" + stationName;
        route[path].second++;
        route[path].first += t-startTime;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path = startStation + "_" + endStation;
        return route[path].first/route[path].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */