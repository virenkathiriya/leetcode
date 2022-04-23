class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int l = 0, r = v.size(), m;
        while (l < r) {
            m = l + (r - l) / 2;
            (v[m] - 1 - m < k) ? l = m + 1 : r = m;
        }
        return l + k;
    }
};