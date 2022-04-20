class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char target) {
        int n = v.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m] > target) r = m - 1;
            else l = m + 1;
        }
        cout << l << " " << r << "\n";
        return l == n ? v[0]: v[l];
    }
};