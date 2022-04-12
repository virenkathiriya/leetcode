class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int len = 2;
        int n = v.size();
        if (n == 1) return 0;
        int ans = 0;
        int d = v[1] - v[0];
        for (int i = 2; i < n; i++) {
            if (v[i] - v[i - 1] == d) {
                len++;
                ans += max(0, len - 2);
            } else {
                d = v[i] - v[i - 1];
                len = 2;
            }
        }
        return ans;
    }
};