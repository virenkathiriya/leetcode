class DSU {
public:
    vector <int> root, rank;
    int n;
    int cnt;

    DSU(int _n): n(_n) {
        root.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            root[i] = i;
            rank[i] = 1;
        }
        cnt = n;
    }

    inline int getCount() {
        return cnt;
    }

    inline int get(int x) {
        return (x == root[x] ? x : (root[x] = get(root[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (rank[x] > rank[y]) {
                root[y] = x;
            } else if (rank[x] < rank[y]) {
                root[x] = y;
            } else {
                root[y] = x;
                rank[x] += 1;
            }
            cnt--;
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& v, vector<vector<int>>& edges) {
        int N = v.size();
        vector<vector<int>> adj(N);
        for (auto &e: edges) {
            int i = e[0], j = e[1];
            if (v[i] >= v[j]) {
                adj[i].push_back(j);
            } else if (v[j] >= v[i]) {
                adj[j].push_back(i);
            }
        }
        map<int, vector<int>> nodes;
        for (int i = 0; i < N; i++) nodes[v[i]].push_back(i);
        
        DSU dsu(N);
        int ans = 0;
        for (auto &[_, list]: nodes) {
            for (int &u: list) {
                for (int &v: adj[u]) {
                    dsu.unite(u, v);
                }
            }
            unordered_map<int, int> dsets;
            for (int &u: list) dsets[dsu.get(u)]++;
            for (auto &[_, size]: dsets) ans += ((size) * (size + 1)) / 2;
        }
        return ans;
    }
};