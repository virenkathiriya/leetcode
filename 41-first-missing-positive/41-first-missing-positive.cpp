class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int N = v.size();
        for (int i = 0; i < N; ++i) while (v[i] > 0 && v[i] <= N && v[v[i] - 1] != v[i]) swap(v[i], v[v[i] - 1]);
        for (int i = 0; i < N; i++) if (v[i] != i + 1) return i + 1;
        return N + 1;
    }
};