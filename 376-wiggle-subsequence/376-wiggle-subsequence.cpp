class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int n = v.size();
        int u = 1, d = 1;
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                u = d + 1;
            } else if (v[i] < v[i - 1]) {
                d = u + 1;
            }
        }
        return max(u, d);
    }
};