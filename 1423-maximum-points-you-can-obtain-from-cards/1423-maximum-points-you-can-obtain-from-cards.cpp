class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int N = v.size();
        for (int i = 1; i < N; i++) v[i] += v[i - 1];
        int ans = 0, sumT = v[N - 1];
        int i = N - 1 - k, j = -1; 
        while (j < k) {
            int sum = sumT - (i >= 0 ? v[i]: 0);
            if (j >= 0) sum += v[j];
            i++, j++;
            ans = max(ans, sum);
        }
        return ans;
    }
};