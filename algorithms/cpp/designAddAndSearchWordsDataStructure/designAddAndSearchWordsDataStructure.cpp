/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
struct TrieNode {
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        this->child = vector<TrieNode*>(26, nullptr);
        this->isEnd = false;
    }
};

void insert(TrieNode *trie, const string& word) {
    for (auto c : word) {
        if (trie->child[c - 'a'] == nullptr) {
            trie->child[c - 'a'] = new TrieNode();
        }
        trie = trie->child[c - 'a'];
    }
    trie->isEnd = true;
}

class WordDictionary {
private:
    TrieNode* trie;
    bool dfs(TrieNode* trie, int index, const string &word) {
        if (index == word.size()) {
            return trie->isEnd;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            if (trie->child[ch - 'a'] != nullptr && dfs(trie->child[ch - 'a'], index + 1, word)) {
                return true;
            }
        } else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (trie->child[i] != nullptr && dfs(trie->child[i], index + 1, word)) {
                    return true;
                }
            }
        } else {
            return false;
        }
        return false;
    }
public:
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        insert(this->trie, word);
    }
    
    bool search(string word) {
        return dfs(this->trie, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end


