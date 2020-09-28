/*
 * @lc app=leetcode.cn id=21 lang=swift
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (64.38%)
 * Likes:    1281
 * Dislikes: 0
 * Total Accepted:    376.9K
 * Total Submissions: 585.3K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var l1 = l1
        var l2 = l2
        var list: ListNode? = ListNode(-1)

        var headNode = list

        while l1 != nil && l2 != nil {
            if l1!.val < l2!.val {
                headNode?.next = l1
                l1 = l1?.next
            }
            else {
                headNode?.next = l2
                l2 = l2?.next
            }
            headNode = headNode?.next
        }

        headNode?.next = l1 == nil ? l2 : l1;

        return list?.next


    }
}

// @lc code=end

