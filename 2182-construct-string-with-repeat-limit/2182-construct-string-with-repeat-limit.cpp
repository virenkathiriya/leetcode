class Solution {
public:
    string repeatLimitedString(string s, int k) {
        vector<int> f(27, 0);
        for (char &c: s) f[c - 'a']++;
        int i = 25;
        string ans;
        bool flag = false;
        
        int bef = -1;
        while (i >= 0) {
            int maxK = flag ? 1: k;
            int x = min(f[i], maxK);
            ans += string(x, i + 'a');
            f[i] -= x;
            if (flag) {
                i = bef;
                flag = false;
            } else {
                if (f[i] > 0) {
                    flag = true;
                    bef = i;
                }
                i--;
                while (i >= 0 && f[i] == 0) i--;
                if (i < 0) break;
            }
            
        }
        return ans;
        // steps:
        // get max count at cur index (assuming there is no char upwards that is remaining)
        // if something remains have a flag set to true
        // get down one and again get back to ramainnig higher char(bef) and try to empty it.
        // continue until empty;
    }
};