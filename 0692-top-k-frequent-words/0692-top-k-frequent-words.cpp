class custom_compare {
public:
    bool operator() (const pair<int, string> &a, const pair<int, string> &b) {
        return (a.first == b.first) ? a.second > b.second: a.first < b.first;
    } 
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string &s: words) mp[s]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, custom_compare> pq;
        for (auto &[key, val]: mp) pq.push({val, key});
        int i = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            words[i++] = it.second;
            pq.pop();
            if (i == k) break; 
        }
        words.resize(k);
        return words;
    }
};