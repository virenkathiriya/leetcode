class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(), v.end());
        int sum = 0, N = v.size();
        vector<int> s(N + 1, 0);
        for (int i = N - 1; i >= 0; i--) {
            s[i] += (i + 1 < N ? s[i + 1]: 0) + v[i];
            if (s[i + 1] + v[i] >= 0) {
                sum += s[i + 1] + v[i];
            } else break;
        }
        return sum;
    }
};