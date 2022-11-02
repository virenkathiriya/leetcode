class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        map<string, bool> vis;
        map<string, bool> bankmap;
        for (string &s: bank) bankmap[s] = true;
        q.push(start);
        vis[start] = true;
        
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string s = q.front();
                q.pop();
                for (int j = 0; j < 8; j++) {
                    for (char c: "ACGT") {
                        string next = s;
                        next[j] = c;
                        if (next == end && bankmap[next]) return ans + 1;
                        
                        if (!vis[next] && bankmap[next]) {
                            q.push(next);
                            vis[next] = true;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};