class Solution {
public:
    int minDeletion(vector<int>& v) {
        int ans = 0;
        int n = v.size();
        for (int i = 0; i < n - 1; i += 2) {
            if (v[i] == v[i + 1]) {
                i--;
                ans++;
            }
        }
        if ((n - ans) % 2 == 1) ans++;
        return ans;
    }
};