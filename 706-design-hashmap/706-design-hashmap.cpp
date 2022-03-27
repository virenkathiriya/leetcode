class MyHashMap {
public:
    static const int size = 1000;
    vector<vector<int>> store[size];
    MyHashMap() {
    }
    
    void put(int key, int value) {
        for (auto &it: store[key % size]) {
            if (it[0] == key) {
                it[1] = value;
                return;
            };
        }
        store[key % size].push_back({key, value});
    }
    
    int get(int key) {
        for (auto &it: store[key % size]) {
            if (it[0] == key) return it[1];
        } 
        return -1;
    }
    
    void remove(int key) {
        int N = store[key % size].size();
        for (int i = 0; i < N; i++) {
            if (store[key % size][i][0] == key) {
                if (i != N - 1) swap(store[key % size][i], store[key % size][N - 1]);
                store[key % size].pop_back();
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