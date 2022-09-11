class Solution {
public:
    int ladderLength(string s, string e, vector<string>& dict) {
        queue<string> q;
        set<string> st;
        for (string &s: dict) st.insert(s); 
        if (st.find(e) == st.end() || s == e) return 0;
        q.push(s);
        int ans = 0;
        while (!q.empty()) {
            ans++;
            int sz = q.size();
            for (int ind = 0; ind < sz; ind++) {
                string u = q.front();
                q.pop();
                for (int i = 0; i < u.size(); i++) {
                    char og = u[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        u[i] = j;
                        if (u == e) return ans + 1;
                        if (st.find(u) == st.end()) continue;
                        st.erase(u);
                        q.push(u);
                    }
                    u[i] = og;
                }
            }
        }
        return 0;
    }
};