class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        int n = s.length();
        for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] > s[i] && (s[i] % 2 == s[j] % 2)) {
                        swap(s[i], s[j]);
                    }
                }
        }
        return stoi(s);
    }
};