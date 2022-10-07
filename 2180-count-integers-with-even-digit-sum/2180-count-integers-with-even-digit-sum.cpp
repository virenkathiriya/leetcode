class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 2; i <= num; i++) {
            string s = to_string(i);
            int cnt = 0;
            for (char &c: s) cnt += ((c - '0') % 2 == 1);
            ans += cnt % 2 == 0;
        }
        return ans;
    }
};