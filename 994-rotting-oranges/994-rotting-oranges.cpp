class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        queue<vector<int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (g[i][j] == 2) {
                    q.push({i, j});
                } else if (g[i][j] == 1) fresh++;
        
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ans = -1;
        while (!q.empty()) {
            int s = q.size(); // rotten oranges at ans + 1 minute
            
            while(s--) {
                auto cur = q.front();
                q.pop();
                for (int i = 0; i < dir.size(); i++) {
                    int x = cur[0], y = cur[1];
                    int xN = x + dir[i][0], yN = y + dir[i][1];
                    if (xN < 0|| xN >= n || yN < 0 || yN >= m) continue;
                    if (g[xN][yN] == 1) {
                        g[xN][yN] = 2;
                        fresh--;
                        q.push({xN, yN});
                    }
                }
            }
            ans++;
        }
        
        if (fresh) 
            return -1;
        
        if (ans == -1) // there are no rotten or fresh oranges 
            return 0;
        return ans;
    }
};