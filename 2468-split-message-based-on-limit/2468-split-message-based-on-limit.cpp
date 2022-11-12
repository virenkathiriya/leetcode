class Solution {
public:
    vector<string> splitMessage(string s, int limit) {
        vector<int> range = {0, 9, 90, 900, 9000, 90000};
        vector<int> rem = {0, 0, 9, 99, 999, 9999};
        int k = limit - 3; 
        int N = s.size();
        
        int ans = INT_MAX;
        for (int i = 1; i <= N; i++) {
            int spaceforchar = 0;
            int parts = to_string(i).size();
            for (int j = parts - 1; j >= 0; j--) if (k - parts - j >= 0) spaceforchar += (k - parts - j) * range[j];
            if (k - (parts * 2) >= 0) spaceforchar += (i - rem[parts]) * (k - parts * 2);
            if (spaceforchar >= N) ans = min(ans, i);
        }
        if (ans == INT_MAX) return {};
        
        int noofparts = ans;
        vector<string> v;
        
        int index = 0;
        for (int i = 1; i <= noofparts; i++) {
            string msg = "<" + to_string(i) + "/" + to_string(noofparts) + ">";
            int msglen = msg.size();
            
            msg = ((index + limit - msglen > N) ? s.substr(index) : s.substr(index, limit - msglen)) + msg;
            index += limit - msglen;
            v.push_back(msg);
            if (index >= N) break;
        }
        return v;
    }
};