class Solution {
public:
    int countHousePlacements(int n) {
        vector<long long> v(n + 1);
        v[0] = 1;
        v[1] = 2;
        for (int i = 2; i <= n; i++) {
            v[i] = (v[i - 1] + v[i - 2]) % 1000000007;
        }
        return (v[n] * v[n]) % 1000000007;
    }
};