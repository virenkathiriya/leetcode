class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string ans;
        for (char &c: s) (st.empty()) ? st.push(c) : ((abs(st.top() - c) == 32) ? st.pop() : st.push(c));
        while (!st.empty()) { ans += st.top(); st.pop(); }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};