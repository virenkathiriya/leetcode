class Solution {
public:
    int tribonacci(int n) {
        vector<int> v(3);
        v[0] = 0, v[1] = 1, v[2] = 1;
        for (int i = 3; i <= n; i++) {
            v[i % 3] = accumulate(v.begin(), v.end(), 0);
        }
        return v[n % 3];
    }
};