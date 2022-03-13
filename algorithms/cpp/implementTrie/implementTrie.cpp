/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
    Trie *searchPrefix(string prefix) {
        Trie *node = this;
        for (char ch : prefix) {
            if (node->children[ch - 'a'] == nullptr) return nullptr; 
            node = node->children[ch - 'a'];
        }
        return node;
    }
public:
    Trie():children(26), isEnd(false) {}
    
    void insert(string word) {
        Trie *node = this;
        for (char ch : word) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
        return;
    }
    
    bool search(string word) {
        Trie *node = this->searchPrefix(word);
        return (node != nullptr && node ->isEnd == true);
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
