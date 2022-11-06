class Solution {
public:
    long long fun(vector<int>& r, vector<int>& f, int i, int j, vector<vector<long long>>& dp) {
        int N = r.size(), M = f.size();
        if (i >= N) return 0;
        if (j >= M) return LLONG_MAX;
        if (dp[i][j] != -1) return dp[i][j];
        
        long long cost = abs(r[i] - f[j]);
        
        long long I = fun(r, f, i + 1, j + 1, dp), E = fun(r, f, i, j + 1, dp);
        
        long long ans = LLONG_MAX;
        
        if (I != LLONG_MAX && E != LLONG_MAX) ans = min(I + cost, E);
        else if (I != LLONG_MAX) ans = I + cost;
        else if (E != LLONG_MAX) ans = E;
        return dp[i][j] = ans;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        
        int N = robot.size(), M = factory.size();
        vector<int> factories;
        for (int i = 0; i < M; ++i) for (int j = 0; j < factory[i][1]; ++j) factories.push_back(factory[i][0]);
        
        vector<vector<long long>> dp(N + 1, vector<long long> (factories.size() + 1, -1));
        return fun(robot, factories, 0, 0, dp);
    }
};