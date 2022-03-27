class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (v[m] > v[m + 1]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};