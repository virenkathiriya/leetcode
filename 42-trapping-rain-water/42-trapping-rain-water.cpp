class Solution {
public:
    int trap(vector<int>& v) {
        /*  
            maintaining 2 arrays of lmax and rmax
            int N = v.size();
            int ans = 0;

            vector<int> l(N, 0), r(N, 0);
            l[0] = v[0];
            for (int i = 1; i < N; i++) l[i] = max(l[i - 1], v[i]);
            r[N - 1] = v[N - 1];
            for (int i = N - 2; i >= 0; i--) r[i] = max(r[i + 1], v[i]);

            for (int i = 0; i < N; i++) ans += min(l[i], r[i]) - v[i];
            return ans;
        */
        /*
            stack<int> st;
            int N = v.size(), ans = 0;
            for(int i = 0; i < N; i++) {
                int x = v[i];
                if (st.empty()) {
                    st.push(i);
                    continue;
                }

                while (!st.empty() && v[st.top()] < x) {
                    int top = st.top(); // bar on top of which water will trap
                    st.pop();
                    if(st.empty())
                        break; // that means it doesn't have left bar to trap water

                    // now st.top() will be either equal or larger than the bar we are trying to tap water into
                    int dx = i - st.top() - 1;
                    int dy = min(x, v[st.top()]) - v[top];

                    ans += dx * dy;
                }
                st.push(i);
            }
            return ans;
        */
        /*
            two pointer
            : optimizing 1st approach
            : maintaining lmax and rmax
            : which ever side is lower will move to the other as in first we atke min of l, r
        */
        int lmax = 0, rmax = 0, ans = 0;
        int l = 0, r = v.size() - 1;
        while (l < r) {
            if (v[l] < v[r]) {
                if (v[l] > lmax) lmax = v[l];
                else ans += lmax - v[l];
                l++;
            } else {
                if (v[r] > rmax) rmax = v[r];
                else ans += rmax - v[r];
                r--;
            }
        }
        return ans;
    }
};