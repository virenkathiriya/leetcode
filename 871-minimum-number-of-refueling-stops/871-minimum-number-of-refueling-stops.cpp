class Solution {
public:
    int minRefuelStops(int t, int f, vector<vector<int>>& v) {
        priority_queue<int> pq;
        int n = v.size(), ans = 0;
        for (int i = 0; i <= n; i++) {
            int d = i == n ? t : v[i][0];
            while (f < d) {
                if (!pq.size()) {
                    // ran out of fuel and if we would have refuel at each station before we will not reach here!
                    return -1;
                }
                // refeul with the largest fuel cap station
                f += pq.top();
                pq.pop();
                ans++;
            }
            if (i < n) pq.push(v[i][1]);
        }
        return ans;
    }
};