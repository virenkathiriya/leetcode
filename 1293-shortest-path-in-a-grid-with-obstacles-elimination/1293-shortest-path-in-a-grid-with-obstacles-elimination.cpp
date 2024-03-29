class Solution {
public:
    int shortestPath(vector<vector<int>>& g, int k) {
        int N = g.size();
        int M = g[0].size();
        
        queue<tuple<int, int, int>> q;
        vector<vector<vector<bool>>> vis(N, vector<vector<bool>> (M, vector<bool> (k + 1, false)));
        q.push({0, 0, 0});
        vis[0][0][0] = true;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                tuple<int, int, int> t = q.front();
                int r = get<0> (t), c = get<1> (t), _k = get<2> (t);
                q.pop();
                
                if ((r == N - 1) && (c == M - 1)) return ans;
                
                for (auto &it: dir) {
                    int R = r + it.first;
                    int C = c + it.second;
                    int K = _k;
                    if (R >= 0 && R < N && C >= 0 && C < M) {
                        if (g[R][C] == 1) K++;
                        if (K <= k && !vis[R][C][K]) {
                            vis[R][C][K] = true;
                            q.push({R, C, K});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};