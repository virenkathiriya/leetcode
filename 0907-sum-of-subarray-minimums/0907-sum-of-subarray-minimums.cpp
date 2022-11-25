class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
        int M = 1000000007;
        stack<int> st;
        long long ans = 0;
        
        for (int i = 0; i <= v.size(); ++i) {
            while (!st.empty() && (i == v.size() || v[st.top()] >= v[i])) {
                int m = st.top();
                st.pop();
                
                int l = st.empty() ? -1: st.top();
                
                long long count = ((m - l) * (i - m)) % M;
                ans = (ans + (count * v[m]) % M) % M;
            }
            st.push(i);
        }
        return ans;
    }
};