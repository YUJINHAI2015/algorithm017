/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (63.39%)
 * Likes:    662
 * Dislikes: 0
 * Total Accepted:    202.3K
 * Total Submissions: 318.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vectorl<int>> result;
        queue<TreeNode*>qu;

        if (!root)
        {
            return result;
        }
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            vector<int> res;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = qu.front();
                res.push_back(node->val);
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            result.push_back(res);
            
        }
        return result;
        
    }
};
// @lc code=end
