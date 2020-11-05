/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (75.81%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    111.5K
 * Total Submissions: 147K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }

    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i<=n; i++) {
            path.push_back(i);
            backtracking(n,k,i+1);
            path.pop_back();
        }
    }
};
// @lc code=end

