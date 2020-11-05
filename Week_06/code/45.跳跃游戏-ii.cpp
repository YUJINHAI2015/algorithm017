/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (37.85%)
 * Likes:    735
 * Dislikes: 0
 * Total Accepted:    88.3K
 * Total Submissions: 233K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 
 * 示例:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 
 * 说明:
 * 
 * 假设你总是可以到达数组的最后一个位置。
 * 
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        // 贪心算法
        // 每次存储可以跳跃的最大数
        int maxPos = 0; // 记录每次跳跃的最大值
        int end = 0;// 每次结束的位置
        int step = 0; // 跳跃次数

        for (int i = 0; i< nums.size()-1;i++) {
            // 判断是否可以跳到最后的位置
            if (maxPos >= i) {
                // 记录可跳跃范围内的最大值
                maxPos = max(maxPos, i + nums[i]);
                // 走到跳跃结束的位置，更新跳跃下一个位置。
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};
// @lc code=end

