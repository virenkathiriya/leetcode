class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int N = roads.size() + 1;
        vector<vector<int>> adj(N);
        vector<int> d(N, 0), p(N, 1);
        for (auto &it: roads) {
            int x = it[0], y = it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
            d[x]++;
            d[y]++;
        }
        
        queue<int> q;
        map<pair<int, int>, bool> vis;
        for (int i = 0; i < N; i++) {
            if (d[i] == 1 && i != 0) {
                q.push(i);
            }
        }
        long long ans = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            if (d[u] != 1) continue;
            
            for (int &v: adj[u]) {
                if (!vis[{u, v}] && !vis[{v, u}]) {
                    vis[{u, v}] = vis[{v, u}] = true;
                    p[v] += p[u];
                    ans += ceil(p[u] / (seats * 1.0));
                    d[v]--, d[u]--;
                    if (v != 0) q.push(v);
                }
            }
        }
        return ans;
    }
};