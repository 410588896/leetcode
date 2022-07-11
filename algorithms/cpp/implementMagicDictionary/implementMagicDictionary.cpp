/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start

struct Trie {
    Trie* child[26];
    bool isFinished;
    Trie() {
        isFinished = false;
        fill(begin(child), end(child), nullptr);
    }
};


class MagicDictionary {
private:
    Trie* trie;
public:
    MagicDictionary() {
        this->trie = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto word : dictionary) {
            Trie* node = this->trie;
            for (char ch : word) {
                if (node->child[ch - 'a'] == nullptr) {
                    node->child[ch - 'a'] = new Trie();
                }
                node = node->child[ch - 'a'];
            }
            node->isFinished = true;
        }
    }
    
    bool search(string searchWord) {
        function<bool(Trie*, int, bool)> dfs = [&](Trie* node, int pos, bool modified) {
            if (pos == searchWord.size()) {
                return modified && node->isFinished;
            }  
            int idx = searchWord[pos] - 'a';
            if (node->child[idx]) {
                if (dfs(node->child[idx], pos + 1, modified)) return true;
            }
            if (!modified) {
                for (int i = 0; i < 26; i++) {
                    if (i != idx && node->child[i]) {
                        if (dfs(node->child[i], pos + 1, true)) return true;
                    }
                }
            }
            return false;
        };
        return dfs(this->trie, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end


