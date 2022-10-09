class Solution {
public:
    int findRadius(vector<int>& a, vector<int>& b) {
        int N = b.size();
        int ans = 0;
        sort(b.begin(), b.end());
        for (int &i: a) {
            int l = 0, r = N - 1;
            int mn = INT_MAX;
            while (l <= r) {
                int m = l + (r - l) / 2;
                mn = min(mn, abs(i - b[m]));
                if (b[m] > i) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            ans = max(ans, mn);
        }
        return ans;
    }
};