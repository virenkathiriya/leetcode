class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        int lb = 0, rb = 0, ans = 0;
        while (l < r) {
            if (v[l] < v[r]) {
                if (lb >= v[l]) ans += lb - v[l];
                else lb = v[l];
                l++;
            } else {
                if (rb >= v[r]) ans += rb - v[r];
                else rb = v[r];
                r--;
            }
        }
        return ans;
    }
};