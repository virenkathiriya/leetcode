class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            (v[m] < v[m + 1]) ? l = m + 1: r = m;
        }
        return l;
    }
};