class Solution {
public:
    struct T {
        vector<T*> v;
        int index;
        vector<int> rip;
        T() {
            v.resize(26, NULL);
            index = -1;
        }
    };
    
    vector<vector<int>> palindromePairs(vector<string>& g) {
        int N = g.size();
        vector<vector<int>> ans;
        T* root = new T();
        
        for (int i = 0; i < N; i++) {
            string s = g[i];
            int m = s.size();
            T* it = root;
            for (int j = m - 1; j >= 0; j--) {
                int alpha = s[j] - 'a'; 
                if (iP(s, 0, j)) (it -> rip).emplace_back(i);
                if (!it -> v[alpha]) it -> v[alpha] = new T();
                it = it -> v[alpha];
            }
            it -> index = i;
        }
        
        for (int i = 0; i < N; i++) {
            string s = g[i];
            int m = s.size();
            T* it = root;
            for (int j = 0; j < m; j++) {
                int alpha = s[j] - 'a';
                if (it -> index != -1 && iP(s, j, m - 1)) ans.push_back({i, it -> index});
                it = it -> v[alpha];
                if (!it) break;
            }
            if (it) {
                if (it -> index != -1 && it -> index != i) ans.push_back({i, it -> index});
                for (int &j: (it -> rip)) ans.push_back({i, j});
            }
        }
        
        return ans;
    }
    
    bool iP(string &s, int i, int j) {
        while (i < j) if (s[i++] != s[j--]) return false; return true;
    }
};