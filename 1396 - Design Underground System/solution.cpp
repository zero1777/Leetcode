class UndergroundSystem {
public:
    unordered_map<string, pair<int, int>> stationTravelTime;
    unordered_map<int, pair<string, int>> customers;
     
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customers[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = customers[id];
        string station = startStation + "_" + stationName;
        
        if (stationTravelTime.find(station) == stationTravelTime.end()) {
            stationTravelTime[station] = make_pair((t - startTime), 1);
        } else {
            auto [time, ppl] = stationTravelTime[station];
            stationTravelTime[station] = make_pair(time + (t - startTime), ppl + 1);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string station = startStation + "_" + endStation;
        auto [time, ppl] = stationTravelTime[station];
        return (double) time / ppl;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */