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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int N = s.size();
        DSU dsu(N);
        for (auto &p: pairs) {
            int u = p[0], v = p[1];
            dsu.unite(u, v);
        }
        map<int, vector<int>> grps;
        for (int i = 0; i < N; i++) grps[dsu.get(i)].push_back(i);
        for (auto &[_, list]: grps) {
            string grps;
            for (int &i: list) grps += s[i];
            sort(grps.begin(), grps.end());
            for (int i = 0; i < grps.size(); i++) s[list[i]] = grps[i];
        }
        return s;
    }
};