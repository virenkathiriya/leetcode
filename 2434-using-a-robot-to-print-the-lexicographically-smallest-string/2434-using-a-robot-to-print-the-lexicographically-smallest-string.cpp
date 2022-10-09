class Solution {
public:
    int get(vector<vector<int>>& f, int ind) {
        for (int i = 0; i < 26; i++) {
            if (f[ind][i] > 0) return i;
        }
        return 26;
    }
    
    string robotWithString(string s) {
        stack<int> t;
        int N = s.size();
        vector<vector<int>> f(N + 1, vector<int>(26, 0));
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) f[i][j] = f[i + 1][j];
            f[i][s[i] - 'a']++;
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
            while (!t.empty() && t.top() <= get(f, i)) {
                ans += (t.top() + 'a');
                t.pop();
            }
            int x = s[i] - 'a';
            if (x <= get(f, i)) 
                ans += (x + 'a');
            else t.push(x);
        }
        
        while (!t.empty()) {
            ans += (t.top() + 'a');
            t.pop();
        }
        return ans;
    }
};