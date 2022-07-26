/*
 * @lc app=leetcode.cn id=1206 lang=cpp
 *
 * [1206] 设计跳表
 */

// @lc code=start
constexpr int MAX_LEVEL = 32;
constexpr double P_FACTOR = 0.25;
struct SkiplistNode {
    int val;
    vector<SkiplistNode *> forward;
    SkiplistNode(int _val, int _maxLevel = MAX_LEVEL) : val(_val), forward(_maxLevel, nullptr) {
        
    }
};
class Skiplist {
private:
    SkiplistNode *head;
    int level;
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    int randomLevel() {
        int lv = 1;
        while (dis(gen) < P_FACTOR && lv < MAX_LEVEL) {
            lv++;
        }
        return lv;
    }
public:
    Skiplist(): head(new SkiplistNode(-1)), level(0), dis(0, 1) {

    }
    
    bool search(int target) {
        SkiplistNode *node = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (node->forward[i] && node->forward[i]->val < target) {
                node = node->forward[i];
            }
        }
        node = node->forward[0];
        if (node && node->val == target) {
            return true;
        }
        return false;
    }
    
    void add(int num) {
        vector<SkiplistNode *> update(MAX_LEVEL, head);
        SkiplistNode *node = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (node->forward[i] && node->forward[i]->val < num) {
                node = node->forward[i];
            }
            update[i] = node;
        }
        int lv = randomLevel();
        level = max(level, lv);
        SkiplistNode *newNode = new SkiplistNode(num);
        for (int i = 0; i < lv; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
        return;
    }
    
    bool erase(int num) {
        vector<SkiplistNode *> update(MAX_LEVEL, nullptr);
        SkiplistNode *node = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (node->forward[i] && node->forward[i]->val < num) {
                node = node->forward[i];
            }
            update[i] = node;
        }
        node = node->forward[0];
        if (!node || node->val != num) {
            return false;
        }
        for (int i = 0; i < level; i++) {
            if (update[i]->forward[i] != node) {
                break;
            }
            update[i]->forward[i] = node->forward[i];
        }
        delete node;
        while (level > 1 && head->forward[level - 1] == nullptr) {
            level--;
        }
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end


