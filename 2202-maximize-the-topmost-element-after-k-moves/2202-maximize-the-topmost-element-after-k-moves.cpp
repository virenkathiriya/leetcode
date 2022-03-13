class Solution {
public:
    int maximumTop(vector<int>& a, int k) {
        int n = a.size();
        int ans = INT_MIN;
        for(int i = 0; i < min(n, k - 1); i++) {
            ans = max(ans, a[i]);
        }
        if(k < n) {
            ans = max(ans, a[k]);
        }
        if(n == 1 && k % 2 == 1) return -1;
        return ans == INT_MIN ? -1 : ans;
    }
};