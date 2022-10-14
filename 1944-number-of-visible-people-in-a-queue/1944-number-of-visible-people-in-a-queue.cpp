class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& a) {
        int N = a.size();
        stack<int> st;
        vector<int> ans(N);
        for (int i = N - 1; i >= 0; --i) {
            int x = a[i], cnt = 0;
            while (!st.empty() && x > st.top()) { ans[i]++, st.pop(); }
            if (!st.empty()) ans[i]++;
            st.push(x);
        }
        return ans;
    }
};