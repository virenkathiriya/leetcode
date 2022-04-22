class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        stack<int> st;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] < v[i]) {
                v[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {v[st.top()] = 0; st.pop();}
        return v;
    }
};