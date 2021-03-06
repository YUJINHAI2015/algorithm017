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
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 到叶子节点，叶子节点是左右节点都为空，根节点不是叶子节点
        /*
        递归法：
        1、确定返回值和参数
        int getDepth(TreeNode* node)
        2、确定终止条件
        if (node == NULL) return 0;
        3、确定单层逻辑
        注意根节点不是叶子节点

        */

       if (!root) return 0;
       int left = minDepth(root->left);
       int right = minDepth(root->right);
       if (root->left == NULL && root->right != NULL) {
           return 1+right;
       }
       if (root->left != NULL && root->right == NULL) {
           return 1+left;
       }
       return 1 + min(left,right);

    }
};
// @lc code=end

