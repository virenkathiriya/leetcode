class Solution {
private:
    struct T {
        vector<T*> children;
        bool isEnd;
        bool appearedOnMaze;
        
        T() {
            children.resize(26, NULL);
            isEnd = false;
            appearedOnMaze = false;
        }
    };
    
public:
    vector<string> findWords(vector<vector<char>>& g, vector<string>& words) {
        T* head = makeT(words);
        vector<string> ans;
        int N = g.size(), M = g[0].size();
        string _;
        
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) f(g, i, j, head, ans, _);
        return ans;
    }
    
    void f(vector<vector<char>>& g, int i, int j, T* u, vector<string> &ans, string& word) {
        int N = g.size();
        int M = g[0].size();
        if (i < 0 || i >= N || j < 0 || j >= M || g[i][j] == '*') return;
        
        int store = g[i][j] - 'a';
        char c = g[i][j];
        u = u -> children[store];
        if (!u) return;
        
        word.push_back(c);
        if (u -> isEnd && !u -> appearedOnMaze) {
            ans.push_back(word);
            u -> appearedOnMaze = true;
        }
        
        g[i][j] = '*';
        f(g, i + 1, j, u, ans, word);
        f(g, i - 1, j, u, ans, word);
        f(g, i, j + 1, u, ans, word);
        f(g, i, j - 1, u, ans, word);
        g[i][j] = c;
        word.pop_back();
    }
    
    T* makeT(vector<string>& words) {
        T* head = new T();
        for (string &s: words) {
            T* cur = head;
            for (char &c: s) {
                int d = c - 'a';
                if (!cur -> children[d]) cur -> children[d] = new T();
                cur = cur -> children[d];
            }
            cur -> isEnd = true;
        }
        return head;
    }
};