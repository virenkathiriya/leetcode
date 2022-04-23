class Solution {
public:
    int specialArray(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = 0; i <= n; i++) {
            int l = upper_bound(begin(v), end(v), i - 1) - begin(v);
            if (n - l == i) return i;
        }
        return -1;
    }
};