/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (43.82%)
 * Likes:    478
 * Dislikes: 0
 * Total Accepted:    64.4K
 * Total Submissions: 146.6K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 记录结果集
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        // 层序遍历队列
        queue<string> toVisit;
        addNextWords(beginWord, wordDict, toVisit);
        int dist = 2;
        while (!toVisit.empty()) {
            int num = toVisit.size();
            for (int i = 0; i < num; i++) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return dist;
                addNextWords(word, wordDict, toVisit);
            }
            dist++;
        }
        return 0;
    }
private:
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        // 主要是这里比较难理解，手动画一下大概就清楚了
        // 第一轮遍历
        // hit ===>遍历ait,bit,cit,dit,eit....在结果集中匹配是否有对应单词
        // hit ===>遍历hat,hbt,hct,hdt,het....在结果集中匹配是否有对应单词
        // hit ===>遍历hia,hib,hic,hid,hie....在结果集中匹配是否有对应单词
        // ===>全部遍历完找到hot加入队列中，这就相当于树的子节点加入队列
        // 第二轮遍历
        // hot ===>遍历aot,bot,cot,dot,eot....在结果集中匹配是否有对应单词
        // ....
        // ===>全部遍历完找到dot，lot加入结果集中。。。。
        for (int p = 0; p < (int)word.length(); p++) {
            char letter = word[p];
            for (int k = 0; k < 26; k++) { 
                word[p] = 'a' + k;
                if (wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[p] = letter;
        } 
    } 
};
// @lc code=end

