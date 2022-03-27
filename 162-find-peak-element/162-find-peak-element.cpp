class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        long long lm = LONG_MIN;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long lE = (m == 0) ? lm : v[m - 1];
            long long rE = (m == n - 1) ? lm: v[m + 1];
            
            if (v[m] > lE && v[m] > rE) return m;
            
            if (lE > v[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};