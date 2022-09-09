class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> f(60, 0);
        for (char &c: num) f[c]++;
        char middle = '*';
        num = "";
        for (int i = '0'; i <= '9'; ++i) {
            num += string(f[i] / 2, i);
            if (f[i] % 2 == 1) middle = i;
        }
        string rev = num;
        reverse(rev.begin(), rev.end());
        num = rev + (middle == '*' ? "" : string(1, middle)) + num;
        int N = num.size();
        int index = 0;
        for (int i = 0; i <= N / 2; i++) {
            if (num[i] != '0') {
                return num.substr(i, N - i * 2);
            }
        }
        return "0";
    }
};