/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (44.38%)
 * Likes:    377
 * Dislikes: 0
 * Total Accepted:    140.3K
 * Total Submissions: 315.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
    int minDepth(TreeNode *root)
    {
        // 层次遍历法
        // 每次都加载一层的数据，只要判断一个节点的左右儿子都位nil，就可以退出

        queue<TreeNode *> que;

        int depth = 0;
        if (root)
            que.push(root);
        while (!que.empty())
        {
            // 确定当前队列中个数
            int size = que.size();
            depth++;
            bool flag = false;
            for (int i = 0; i < size; i++)
            {
                // 取出第一个节点
                TreeNode *node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        return depth;
    }
};
// @lc code=end
