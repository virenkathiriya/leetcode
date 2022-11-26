class Solution {
public:
    int f(int i, int N, vector<vector<int>> &jobs, vector<int> &dp) {
        if (i >= N) return 0;
        if (dp[i] != -1) return dp[i];
        
        int j = i + 1;
        while (j < N && jobs[j][0] < jobs[i][1]) ++j; // getting next possible jobs that can be done
        
        int I = jobs[i][2] + f(j, N, jobs, dp);
        int E = f(i + 1, N, jobs, dp);
        
        return dp[i] = max(I, E);
    }
    
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int N = s.size();
        vector<vector<int>> jobs(N);
        for (int i = 0; i < N; ++i) {
            jobs[i] = {s[i], e[i], p[i]};
        }
        sort(jobs.begin(), jobs.end());
        vector<int> dp(N, -1);
        return f(0, N, jobs, dp);
    }
};