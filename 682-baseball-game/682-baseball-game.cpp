class Solution {
public:
    int calPoints(vector<string>& v) {
        stack<int> s;
        int sum = 0;
        for (string c: v) {
            if (c == "+") {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                int z = x + y;
                s.push(y);
                s.push(x);
                s.push(z);
                sum += z;
            } else if (c == "C") {
                sum -= s.top();
                s.pop();
            } else if (c == "D") {
                int x = s.top();
                s.push(2 * x);
                sum += 2 * x;
            } else {
                int x = stoi(c);
                sum += x;
                s.push(x);
            }
        }
        return sum;
    }
};