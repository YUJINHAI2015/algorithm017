/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (66.03%)
 * Likes:    377
 * Dislikes: 0
 * Total Accepted:    80K
 * Total Submissions: 121.1K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// https://mp.weixin.qq.com/s/Osw4LQD2xVUnCJ-9jrYxJA
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;

        if (root == NULL) return result;
        traversal(root, path, result);
        return result;
    }

    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        // 每次递归往里面加值
        path.push_back(cur->val);
        // 递归终止条件
        if (cur->left == NULL && cur->right == NULL) {
            string sPath;
            // 到子节点的时候判断一下path里面有多少个节点，就是路径有多长
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }

        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back(); // 回溯
        }
        if (cur->right) {
            traversal(cur->right, path, result);
            path.pop_back(); // 回溯
        }
    }
};
// @lc code=end

