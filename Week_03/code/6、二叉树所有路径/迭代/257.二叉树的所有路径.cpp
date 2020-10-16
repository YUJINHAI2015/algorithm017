/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (66.11%)
 * Likes:    383
 * Dislikes: 0
 * Total Accepted:    80.6K
 * Total Submissions: 121.9K
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
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        stack<TreeNode *> treeSt; // 保存树的遍历节点
        stack<string> pathSt;     // 保存遍历路径的节点
        vector<string> result;    // 保存最终路径集合
        if (root == NULL)
            return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));

        while (!treeSt.empty())
        {

            TreeNode *node = treeSt.top();
            treeSt.pop(); // 取出节点 中
            string path = pathSt.top();
            pathSt.pop(); // 取出该节点对应的路径
            if (node->left == NULL && node->right == NULL)
            { // 遇到叶子节点
                result.push_back(path);
            }
            if (node->right)
            { // 右
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if (node->left)
            { // 左
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }
        return result;
    }
};
// @lc code=end
