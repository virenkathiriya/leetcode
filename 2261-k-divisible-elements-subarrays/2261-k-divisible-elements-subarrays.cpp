class Solution {
public:
    struct T {
        unordered_map<int, T*> next;
        T() {}
    };
    
    int countDistinct(vector<int>& v, int k, int p) {
        T* root = new T();
        int n = v.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            T* cur = root;
            int m = 0;
            for (int j = i; j < n; j++) {
                if (v[j] % p == 0) {
                    m++;
                }
                if (m > k) break;
                if (!cur -> next[v[j]]) {
                    cur -> next[v[j]] = new T();
                    ans++;
                }
                cur = cur -> next[v[j]];
            }
        }
        return ans;
    }
};