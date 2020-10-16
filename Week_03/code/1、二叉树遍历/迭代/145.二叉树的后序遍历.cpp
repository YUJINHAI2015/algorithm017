/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.44%)
 * Likes:    452
 * Dislikes: 0
 * Total Accepted:    150.4K
 * Total Submissions: 205.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // 出栈：左右中
        // 入栈：中右左
        vector<int> result;
        stack<TreeNode*>st;
        if (!root) return result;
        st.push(root);
        while(!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            if (node != NULL)
            {
                st.push(node);
                st.push(NULL);
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);

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

