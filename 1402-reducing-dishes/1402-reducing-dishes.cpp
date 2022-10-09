class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(), v.end());
        int sum = 0, N = v.size(), cnt = 0;
        vector<int> s(N, 0);
        
        for (int i = 0; i < N; i++) {
            if (v[i] > 0) { 
                cnt++; 
                sum += v[i] * cnt; 
            }
        }
        
        for (int i = N - 1; i >= 0; i--) {
            s[i] += (i + 1 < N ? s[i + 1]: 0) + v[i];
            if (v[i] <= 0) {
                if (sum <= 0) break;
                if (s[i + 1] + v[i] >= 0) {
                    sum += s[i + 1] + v[i];
                } else break;
            }
        }
        return sum;
    }
};