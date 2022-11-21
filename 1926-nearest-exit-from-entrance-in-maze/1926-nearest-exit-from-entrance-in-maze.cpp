class Solution {
public:
    int nearestExit(vector<vector<char>>& g, vector<int>& s) {
        int n = g.size(), m = g[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;
        
        q.push({s[0], s[1]});
        g[s[0]][s[1]] = 1;
        while (!q.empty()) {
            int sz = q.size();
            ans++;
            for (int i = 0; i < sz; i++) {
                pair<int, int> p = q.front();
                q.pop();
                for (vector<int> &di: d) {
                    int x = p.first + di[0], y = p.second + di[1];
                    if (x >= n or x < 0 or y >= m or y < 0) continue;
                    if ((x == 0 or y == 0 or (x == n - 1) or (y == m - 1))) {
                        if (g[x][y] == '.') return ans;
                        continue;
                    }
                    if (g[x][y] == '.') {
                        g[x][y] = 1;
                        q.push({x, y});
                    }
                } 
            }
            
        }
        return -1;
    }
};