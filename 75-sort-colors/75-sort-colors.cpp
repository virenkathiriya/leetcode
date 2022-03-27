class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        for (int i = l; i <= r;) {
            while (l < n && v[l] == 0) l++;
            while (l < r && v[r] == 2) r--;
            if (i < l) i = l;
            if (i >= n || !(l <= r)) break;
            if (v[i] == 0) {
                swap (v[l], v[i]);
                l++;
            } else if (v[i] == 2) {
                swap (v[r], v[i]);
                r--;
            } else {
                i++;
            }
        }
    }
};