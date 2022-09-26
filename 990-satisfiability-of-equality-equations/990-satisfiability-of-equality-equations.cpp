class Solution {
public:
    int f(int x, vector<int> &v) { return (x == v[x]) ? x : v[x] = f(v[x], v);}
    bool equationsPossible(vector<string>& v) {
        vector<int> parent(26);
        for (int i = 0; i < 26; i++) parent[i] = i;
        for (string &s: v) if (s[1] == '=') parent[f(s[0] - 'a', parent)] = f(s[3] - 'a', parent);
        for (string &s: v) if (s[1] == '!' && f(s[0] - 'a', parent) == f(s[3] - 'a', parent)) return false;
        return true;
    }
};