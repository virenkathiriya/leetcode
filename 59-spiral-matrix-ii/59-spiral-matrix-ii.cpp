class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int i = 0, j = 0, cnt = 0;
        int dir = 0;
        /*
        0 - left;
        1 - down;
        2 - right;
        3 - up;
        */
        while (cnt < n * n) {
            if (ans[i][j] == 0) {
                cnt++;
                ans[i][j] = cnt;
            }
            switch (dir) {
                case 0:
                    (j + 1 < n && ans[i][j + 1] == 0) ? j++: dir++;
                    break;
                case 1:
                    (i + 1 < n && ans[i + 1][j] == 0) ? i++: dir++;
                    break;
                case 2:
                    (j - 1 >= 0 && ans[i][j - 1] == 0) ? j--: dir++;
                    break;
                case 3:
                    (i - 1 >= 0 && ans[i - 1][j] == 0) ? i--: dir++;
                    break;
            }
            dir %= 4;
        } 
        return ans;
    }
};