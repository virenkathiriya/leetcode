class Solution {
public:
    string robotWithString(string s) {
        stack<int> t;
        int N = s.size();
        vector<int> f(N + 1, 26);
        for (int i = N - 1; i >= 0; i--) {
            f[i] = min(f[i + 1], s[i] - 'a');
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
            while (!t.empty() && t.top() <= f[i]) {
                ans += (t.top() + 'a');
                t.pop();
            }
            int x = s[i] - 'a';
            if (x <= f[i]) 
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