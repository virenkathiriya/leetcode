class MyHashMap {
public:
    vector<vector<int>> store[1000];
    MyHashMap() {
    }
    
    void put(int key, int value) {
        for (auto &it: store[key % 1000]) {
            if (it[0] == key) {
                it[1] = value;
                return;
            };
        }
        store[key % 1000].push_back({key, value});
    }
    
    int get(int key) {
        for (auto &it: store[key % 1000]) {
            if (it[0] == key) return it[1];
        } 
        return -1;
    }
    
    void remove(int key) {
        int N = store[key % 1000].size();
        for (int i = 0; i < N; i++) {
            if (store[key % 1000][i][0] == key) {
                if (i != N - 1) swap(store[key % 1000][i], store[key % 1000][N - 1]);
                store[key % 1000].pop_back();
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */