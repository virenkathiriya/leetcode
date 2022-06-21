class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = h.size();
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (h[i] < h[i + 1]) {
                pq.push(h[i + 1] - h[i]);
                if (pq.size() > l) {
                    sum += pq.top();
                    pq.pop();
                }
                if (sum > b) return i;
            }
        }
        return n - 1;
    }
};