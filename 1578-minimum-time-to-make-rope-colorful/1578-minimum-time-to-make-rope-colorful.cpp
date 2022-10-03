class Solution {
public:
    int minCost(string c, vector<int>& v) {
        int ans = 0, N = v.size();
        int i = 0, j = 0;
        while (i < N && j < N) {
            int sum = 0;
            while (j < N && c[i] == c[j]) j++;
            ans += accumulate(v.begin() + i, v.begin() + j, 0) - *max_element(v.begin() + i, v.begin() + j);
            i = j;
        }
        return ans;
    }
};