/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (52.98%)
 * Likes:    1064
 * Dislikes: 0
 * Total Accepted:    215.3K
 * Total Submissions: 405.8K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以运用递归和迭代两种方法解决这个问题吗？
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left);   // 将左子树头结点加入队列
        que.push(root->right);  // 将右子树头结点加入队列
        while (!que.empty()) {  // 接下来就要判断这这两个树是否相互翻转
            TreeNode* leftNode = que.front(); que.pop();    
            TreeNode* rightNode = que.front(); que.pop();
            if (!leftNode && !rightNode) {  // 左节点为空、右节点为空，此时说明是对称的
                continue;
            }

            // 左右一个节点不为空，或者都不为空但数值不相同，返回false
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) { 
                return false;
            }
            que.push(leftNode->left);   // 加入左节点左孩子
            que.push(rightNode->right); // 加入右节点右孩子
            que.push(leftNode->right);  // 加入左节点右孩子
            que.push(rightNode->left);  // 加入右节点左孩子
        }
        return true;
    }
};
// @lc code=end

