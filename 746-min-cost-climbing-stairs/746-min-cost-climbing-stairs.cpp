class Solution {
public:
    int minCostClimbingStairs(vector<int>& v) {
        int a = v[0], b = v[1];
        int i = 2, N = v.size();
        while (i < N) {
            int c = min(a, b) + v[i];
            a = b;
            b = c;
            i++;
        }
        return min(a, b);
    }
};