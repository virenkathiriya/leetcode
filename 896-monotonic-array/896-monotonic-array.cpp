class Solution {
public:
    bool isMonotonic(vector<int>& v) {
        int n = v.size();
        if (n == 1) return true;
        bool isInc = false;
        bool isDec = false;
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                if (isDec) return false;
                isInc = true;
            } else if (v[i] < v[i - 1]) {
                if (isInc) return false;
                isDec = true;
            }
        }
        return true;
    }
};