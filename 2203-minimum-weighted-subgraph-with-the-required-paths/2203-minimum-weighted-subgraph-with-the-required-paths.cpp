class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<long long, long long>>> adj(n), radj(n);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            radj[it[1]].push_back({it[0], it[2]});
        }
        
        auto dijkstra = [&]( vector<vector<pair<long long, long long>>> &vp, int src, vector<long long> &dis) {
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<int, int>>> pq;
            dis[src] = 0;
            pq.push({0, src});
            while(!pq.empty()) {
                auto [val, u] = pq.top();
                pq.pop();
                if(val > dis[u]) continue;
                for (auto &[v, wt] : vp[u]) {
                    if(dis[u] + wt < dis[v]) {
                        dis[v] = dis[u] + wt;
                        pq.push({dis[v], v});
                    }
                }
            }
        };
        vector<long long> ds1(n, LONG_MAX), ds2(n, LONG_MAX), dd(n, LONG_MAX);
        dijkstra(adj, src1, ds1); dijkstra(adj, src2, ds2); dijkstra(radj, dest, dd);
        long long ans = LONG_MAX;
        for(int i = 0; i < n; i++) 
            if(max({ds1[i], ds2[i], dd[i]}) != LONG_MAX) 
                ans = min(ans, ds1[i] + ds2[i] + dd[i]);
        return ans == LONG_MAX ? -1 : ans;
    }
};