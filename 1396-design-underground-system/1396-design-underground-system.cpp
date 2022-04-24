class UndergroundSystem {
private:
    map<int, pair<string, int>> cIn;
    map<pair<string, string>, pair<double, int>> avg;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        cIn[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s = cIn[id].first;
        string d = stationName;
        int timeTaken = t - cIn[id].second;
        avg[{s, d}].first += timeTaken;
        avg[{s, d}].second++;
    }
    
    double getAverageTime(string s, string d) {
        return avg[{s, d}].first / avg[{s, d}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */