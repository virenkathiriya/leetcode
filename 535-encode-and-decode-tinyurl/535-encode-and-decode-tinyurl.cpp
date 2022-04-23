class Solution {
private:
    string base;
    unordered_map<string, string> e, d;
    std::string gen_random() {
        string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        std::string s;
        s.reserve(6);
        int N = alphanum.size();
        for (int i = 0; i < 6; ++i) s += alphanum[rand() % (N - 1)];
        return d.count(s) ? gen_random(): s;
    }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (e.count(longUrl)) return e[longUrl];
        string r = gen_random();
        e[longUrl] = r;
        d[r] = longUrl;
        return r;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return d[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));