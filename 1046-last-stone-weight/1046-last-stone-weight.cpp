class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int> pq;
        for (int &x: v) pq.push(x);
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a != b) pq.push(abs(b - a));
        }
        if (pq.size() == 0) return 0;
        return pq.top();
    }
};