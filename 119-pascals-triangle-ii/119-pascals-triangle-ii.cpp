class Solution {
public:
    vector<int> getRow(int n) {
        if (n == 0) return {1};
        if (n == 1) return {1, 1};
        vector<int> v(n + 1, 0);
        v[0] = v[1] = 1;
        for (int i = 2; i <= n; i++) {
            int pre = 1;
            for (int j = 1; j < i; j++) {
                int t = pre + v[j];
                pre = v[j];
                v[j] = t;
            }
            v[i] = 1;
        }
        return v;
    }
};