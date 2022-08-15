class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int d = 1, cnt = 0;
        vector<int> ans;
        int i = 0, j = 0;
        int n = v.size(), m = v[0].size();
        int set = -101;
        while (cnt < n * m) {
            if (v[i][j] != set) {
                ans.push_back(v[i][j]);
                cnt++;
                v[i][j] = set;
            }
            switch (d) {
                case 1: {
                    // right
                    (j + 1 < m && v[i][j + 1] != set) ? j++ : d++;
                    break;
                }
                case 2: {
                    // down
                    (i + 1 < n && v[i + 1][j] != set) ? i++ : d++;
                    break;
                }
                case 3: {
                    // left
                    (i - 1 >= 0 && v[i - 1][j] != set) ? i-- : d++;
                    break;
                }
                case 0: {
                    // up
                    (j - 1 >= 0 && v[i][j - 1] != set) ? j-- : d++;
                    break;
                }
            }
            d %= 4;
        }
        return ans;
    }
};