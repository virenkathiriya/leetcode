class Solution {
public:
    int countPoints(string s) {
        vector<vector<bool>> v(10, vector<bool>(3, false));
        for(int i = 0; i < s.length(); i += 2) {
            char c = s[i];
            int ind = s[i + 1] - '0';
            if (s[i] == 'G') v[ind][0] = true;
            else if (s[i] == 'B') v[ind][1] = true;
            else v[ind][2] = true;
        }
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            cnt += (v[i][0] && v[i][1] && v[i][2]);
        }
        return cnt;
    }
};