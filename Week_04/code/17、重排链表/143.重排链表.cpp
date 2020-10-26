/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (56.54%)
 * Likes:    419
 * Dislikes: 0
 * Total Accepted:    63.4K
 * Total Submissions: 106.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // stack
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases

        stack<ListNode *> st;

        ListNode *ptr = head;
        while (ptr != NULL)
        {
            st.push(ptr);
            ptr = ptr->next;
        }
        int size = st.size();
        ListNode *pptr = head;

        for (int i = 0; i < size/2; i++)
        {
            ListNode *node = st.top();
            st.pop();

            // 4的下个节点
            node->next = pptr->next;
            // 1的下个节点
            pptr->next = node;
            // 移动指针
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
        
        
    }
};
// @lc code=end

