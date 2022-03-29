class Solution {
public:
    bool canJump(vector<int>& v) {
        int canReach = 0, n = v.size();
        for (int i = 0; i < n && i <= canReach; i++) {
            canReach = max(canReach, i + v[i]);
        }
        return canReach >= n - 1;
    }
};