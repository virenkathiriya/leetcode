class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;
        for (char &c: s) {
            if (c == ',') continue;
            if (c == ')') {
                int f = 0, t = 0;
                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    if (st.top() == 'f') f++;
                    if (st.top() == 't') t++;
                    st.pop();
                }
                char y = st.top();
                st.pop();
                char res = ' ';
                if (y == '!') {
                    res = (f > 0) ? 't': 'f';
                } else if (y == '&') {
                    res = (f > 0) ? 'f' : 't';
                } else if (y == '|') {
                    res = (t > 0) ? 't' : 'f';
                }
                st.push(res);
            } else {
                st.push(c);
            }
        }
        return st.top() == 't';
    }
};