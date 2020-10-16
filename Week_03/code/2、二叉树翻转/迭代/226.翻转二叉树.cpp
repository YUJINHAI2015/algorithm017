/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 *
 * https://leetcode-cn.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (77.29%)
 * Likes:    638
 * Dislikes: 0
 * Total Accepted:    147.6K
 * Total Submissions: 190.9K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * 翻转一棵二叉树。
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * 输出：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * 备注:
 * 这个问题是受到 Max Howell 的 原问题 启发的 ：
 * 
 * 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
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
    TreeNode* invertTree(TreeNode* root) {
        // 迭代法
        // 前序遍历：中左右
        // 入栈顺序：右左中

        stack<TreeNode*> st;
        if (root != NULL) st.push(root);

        while (!st.empty())
        {
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
                swap(node->left,node->right);
            }
            
        }
        return root;
        


    }
};
// @lc code=end

