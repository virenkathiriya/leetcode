class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> v;
        for (string &s: arr) {
            int x = c(s);
            if (x != -1)
                v.push_back(x);
        }
        int N = v.size();
        int ans = 0;
        for (int i = 0; i < (1 << N); i++) {
            int o = 0;
            for (int j = 0; j < N; j++) {
                if ((i & (1 << j)) > 0) {
                    if ((o & v[j]) == 0) {
                        o |= v[j];
                    }
                }
            }
            ans = max(ans, __builtin_popcount(o));
        }
        return ans;
    }
private:
    int c(string s) {
        int ans = 0;
        for (char &c: s) {
            if ((ans & (1 << (c - 'a'))) > 0) return -1;
            ans |= (1 << (c - 'a'));
        }
        return ans;
    }
};