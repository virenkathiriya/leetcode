class Solution {
public:
    int minOperations(int N) {
        int ans = 0;
        for (int i = 1; i <= N; i += 2) {
            ans += (N - i);
        }
        return ans;
    }
};