class Solution {
public:
    int findLengthOfLCIS(vector<int>& v) {
        int cnt = 1;
        int ans = 1, n = v.size();
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        return max(cnt, ans);
    }
};