class Solution {
public:
    int maxArea(vector<int>& v) {
        int l = 0, r = v.size() - 1, ans = 0;
        while (l < r) {
            ans = max(min(v[l], v[r]) * (r - l), ans);
            (v[l] < v[r]) ? l++ : r--;
        }
        return ans;
    }
};