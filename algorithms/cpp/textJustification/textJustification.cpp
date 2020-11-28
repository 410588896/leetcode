/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

/***************************************
* 
* Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
* 
* You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
* 
* Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
* 
* For the last line of text, it should be left justified and no extra space is inserted between words.
* 
* Note:
* 
* A word is defined as a character sequence consisting of non-space characters only.
* Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
* The input array words contains at least one word.
*  
* 
* Example 1:
* 
* Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
* Output:
* [
*    "This    is    an",
*    "example  of text",
*    "justification.  "
* ]
* Example 2:
* 
* Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
* Output:
* [
*   "What   must   be",
*   "acknowledgment  ",
*   "shall be        "
* ]
* Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
* Note that the second line is also left-justified becase it contains only one word.
* Example 3:
* 
* Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
* Output:
* [
*   "Science  is  what we",
*   "understand      well",
*   "enough to explain to",
*   "a  computer.  Art is",
*   "everything  else  we",
*   "do                  "
* ]
*  
* 
* Constraints:
* 
* 1 <= words.length <= 300
* 1 <= words[i].length <= 20
* words[i] consists of only English letters and symbols.
* 1 <= maxWidth <= 100
* words[i].length <= maxWidth
* 
***************************************/

// @lc code=start
class Solution {
private:
    string fillWords(vector<string>& words, int begin, int end, int maxWidth, bool lastLine = false) {
        int wordCount = end - begin + 1;
        int spaceCount = maxWidth + 1 - wordCount;
        for (int i = begin; i <= end; i++)
            spaceCount -= words[i].size();
        int spaceSuffix = 1;    // 词尾空格
        int spaceAvg = (wordCount == 1) ? 1 : spaceCount / (wordCount - 1);     
        int spaceExtra = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1);   
        string res;
        for (int i = begin; i < end; i++) {
            res += words[i];    
            if (lastLine) {
                fill_n(back_inserter(res), 1, ' ');
                continue;
            }
            fill_n(back_inserter(res), spaceSuffix + spaceAvg + ((i - begin) < spaceExtra), ' ');  
        }
        res += words[end];
        fill_n(back_inserter(res), maxWidth - res.size(), ' ');
        return res;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        if (n <= 0) return res;
        int begin = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += words[i].size() + 1;
            if (i + 1 == n || cnt + words[i + 1].size() > maxWidth) {
                res.push_back(fillWords(words, begin, i, maxWidth, i + 1 == n));
                begin = i + 1;
                cnt = 0;
            }
        }
        return res;
    }
};
// @lc code=end


