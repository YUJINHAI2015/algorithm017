/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (66.89%)
 * Likes:    370
 * Dislikes: 0
 * Total Accepted:    174.8K
 * Total Submissions: 261.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {

        // 迭代法 前序遍历
        // 1、出栈的顺序根左右
        // 2、入栈的顺序右左根

        vector<int> result;
        if (!root)
        {
            return result;
        }
        
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();

            if (node != NULL)
            {
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
                st.push(node);
                st.push(NULL);

            }
            else {

                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};

// @lc code=end
