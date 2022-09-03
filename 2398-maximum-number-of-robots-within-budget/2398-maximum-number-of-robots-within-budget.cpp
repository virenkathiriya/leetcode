class Solution {
public:
    int maximumRobots(vector<int>& t, vector<int>& c, long long budget) {
        priority_queue<pair<long long, long>> pq;
        int N = t.size();
        int ans = 0;
        long long runningCostSum = 0;
        int start = 0;
        for (int i = 0; i < N; i++) {
            int Time = t[i];
            int RunningCost = c[i];
            pq.push({Time, i});
            
            runningCostSum += RunningCost;
            
            long long totalCost = pq.top().first + (i - start + 1LL) * (runningCostSum);
            if (totalCost > budget && (i - start + 1) > 0) {
                runningCostSum -= c[start];
                start++;
                // remove invalid indexes
                while (!pq.empty() && pq.top().second < start) {
                    pq.pop();
                }
                totalCost = pq.top().first + (i - start + 1LL) * (runningCostSum);
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};