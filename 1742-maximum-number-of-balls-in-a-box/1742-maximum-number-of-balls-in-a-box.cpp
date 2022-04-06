class Solution {
public:
    int countBalls(int l, int r) {
        vector<int> mp(50, 0);
        int ans = 0;
        for (int i = l; i <= r; i++) {
            int sum = 0;
            int m = i;
            while (m) {
                sum += m % 10;
                m /= 10;
            }
            ans = max(++mp[sum], ans);
        }
        return ans;
    }
};