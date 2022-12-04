class Solution {
public:
    int minimumAverageDifference(vector<int>& v) {
        int N = v.size();
        vector<long long> p(N, 0);
        p[0] = v[0];
        for (int i = 1; i < N; i++) p[i] = p[i - 1] + v[i];
        
        int ans = INT_MAX;
        int minIndex = 0;
        for (int i = 0; i < N; i++) {
            int x = abs(
                (p[i] / (i + 1)) - 
                (
                    (i == N - 1) 
                    ? 0
                    : (p[N - 1] - p[i]) / (N - 1 - i)
                )
            );
            if (x < ans) {
                ans = x;
                minIndex = i;
            }
        }
        return minIndex;
    }
};