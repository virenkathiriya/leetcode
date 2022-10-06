class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store[key].empty()) return "";
        pair<int, string> p = {timestamp,  ""};
        auto it = upper_bound(store[key].begin(), store[key].end(), p,  [&](const pair<int, string> &a, const pair<int, string> &b) {
            return a.first < b.first;
        });
        if (it == store[key].begin()) return "";
        it--;
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */