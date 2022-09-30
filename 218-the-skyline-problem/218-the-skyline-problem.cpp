class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& v) {
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> ans;
        int N = v.size(), h = -1, x = -1, i = 0;
        while (i < N || !pq.empty()) {
            x = pq.empty() ? v[i][0] : pq.top().second;
            if (i >= N || v[i][0] > x) {
                while (!pq.empty() && pq.top().second <= x) pq.pop();
            } else {
                x = v[i][0];
                while (i < N && v[i][0] == x) {
                    pq.push({v[i][2], v[i][1]}), i++;
                }
            }
            h = pq.empty() ? 0: pq.top().first;
            if (ans.empty() || ans.back()[1] != h) ans.push_back({x, h});
        }
        return ans;
    }
};