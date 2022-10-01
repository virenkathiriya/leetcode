class Solution {
public:
    bool f(vector<int> &a, vector<int> &b) {
        bool ok = true;
        for (int i = 'A'; i <= 'Z'; i++) ok &= (a[i] >= b[i]);
        for (int i = 'a'; i <= 'z'; i++) ok &= (a[i] >= b[i]);
        
        return ok;
    }
    
    string minWindow(string s, string t) {
        vector<int> b(256, 0);
        for (char &c: t) b[c]++;
        
        int i = 0, j = 0, len = INT_MAX, index = -1, N = s.size();
        vector<int> a(256, 0);
        while (true) {
            if (j >= N) break;
            while (j < N && !f(a, b)) {
                a[s[j]]++;
                j++;
            }
            while (i < j && i < N && f(a, b)) {
                int curWindowLength = j - i;
                int ind = i;
                if (curWindowLength < len) {
                    len = curWindowLength;
                    index = ind;
                }
                a[s[i]]--;
                i++;
            }
        }
        return index == -1 ? "": s.substr(index, len);
    }
};