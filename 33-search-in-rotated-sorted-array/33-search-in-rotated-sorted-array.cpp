class Solution {
public:
    int search(vector<int>& v, int target) {
        int n = v.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int mid = v[m];
            if (mid == target) return m;
            if (!((v[m] < v[0] && target < v[0]) || (v[m] >= v[0] && target >= v[0]))) {
                if (v[0] > target) {
                    mid = INT_MIN;
                } else {
                    mid = INT_MAX;
                }
            }
            if (mid > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};