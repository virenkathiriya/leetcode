class Solution {
public:
    vector<int> findBall(vector<vector<int>>& g) {
        int N = g.size(); 
        int M = g[0].size();
        vector<int> ans(M, 0);
        
        for (int c = 0; c < M; ++c) {
            int cur = c; // starting column
            for (int r = 0; r < N; ++r) {
                int next = cur + g[r][cur]; // side which we will row through -1: left 1: right
                if (next < 0 || next > M - 1 // out
                   || g[r][cur] != g[r][next]) // stuck
                {
                    ans[c] = -1;
                    break;
                }
                // gping in next row the starting column will be next
                ans[c] = next;
                cur = next;
            }
        }
        return ans;
    }
};