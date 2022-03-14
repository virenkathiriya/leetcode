class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        map<int, int> exist;
        for (int &x: a) exist[x]++;
        for (int &x: b) if (exist[x]) {
            ans.push_back(x);
            exist[x]--;
        }
        return ans;
    }
};