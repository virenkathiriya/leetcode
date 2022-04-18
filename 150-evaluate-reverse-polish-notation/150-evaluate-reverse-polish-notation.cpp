class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string &st: tokens) {
            if (st.size() > 1 || (isdigit(st[0]))) {
                s.push(stoi(st));
                continue;
            }
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            if (st == "+") {
                s.push(x + y);
            } else if (st == "-") {
                s.push(y - x);
            } else if (st == "*") {
                s.push(x * y);
            } else {
                s.push(y / x);
            }
        }
        return s.top();
    }
};