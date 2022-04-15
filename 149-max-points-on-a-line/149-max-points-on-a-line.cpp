class Solution {
public:
    double f(vector<int> &a, vector<int> &b) {
        if (b[0] - a[0] == 0) return 1e5;
        return ((b[1] - a[1]) * 1.0) / (b[0] - a[0]);
    }
    int maxPoints(vector<vector<int>>& vp) {
        int ans = 1;
        for (int i = 0; i < vp.size(); i++) {
            unordered_map<double, int> cnt;
            int maxCandidate = 0;
            for (int j = 0; j < vp.size(); j++) {
                if (i != j) {
                    cnt[f(vp[i], vp[j])]++;
                    maxCandidate = max(maxCandidate, cnt[f(vp[i], vp[j])]);
                }
            }
            ans = max(maxCandidate + 1, ans);
        }
        return ans;
    }
};