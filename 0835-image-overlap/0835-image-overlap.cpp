class Solution {
public:
    int f(int x, int y, vector<vector<int>> &a, vector<vector<int>> &b) {
        int cnt0 = 0, cnt1 = 0;
        int rRow = 0, N = a.size();
        for (int i = y; i < N; i++) {
            int rCol = 0;
            for (int j = x; j < N; j++) {
                if (a[i][j] == 1 && a[i][j] == b[rRow][rCol]) cnt0++;
                if (a[i][rCol] == 1 && a[i][rCol] == b[rRow][j]) cnt1++;
                rCol++;
            }
            rRow++;
        }
        return max(cnt0, cnt1);
    }
    
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int ans = 0;
        int N = a.size();
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ans = max({ans, f(i, j, a, b), f(i, j, b, a)});
        return ans;
    }
};