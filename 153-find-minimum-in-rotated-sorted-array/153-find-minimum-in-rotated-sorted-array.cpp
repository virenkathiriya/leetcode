class Solution {
public:
    int findMin(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (v[m] > v[r]) l = m + 1;
            else r = m;
        }
        return v[l];
    }
};