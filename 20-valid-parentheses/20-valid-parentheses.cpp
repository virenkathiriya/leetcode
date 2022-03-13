class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        for(char &c: st) {
            if (c == '{' or c == '[' or c == '(') s.push(c);
            else {
                if(!s.empty()) {
                    char top = s.top();
                    if (
                        (c == '}' && top == '{')
                        or 
                        (c == ']' && top == '[')
                        or
                        (c == ')' && top == '(')
                    ) s.pop();
                    else 
                        return false;
                } else 
                    return false;
            }
        }
        return s.empty();
    }
};