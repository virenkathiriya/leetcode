class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> f(100005, 0);
        int ans = 0, number = -1;
        for (int &x: nums) {
            f[x]++;
            if (x % 2 == 0) {
                if (ans == f[x] && x < number) {
                    number = x;
                } else if (ans < f[x]) {
                    number = x;
                }
                ans = max(ans, f[x]);
            }
        }
        return number;
    }
};