/*
 * @lc app=leetcode.cn id=1 lang=swift
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var sum: [Int] = []
        var dict: [Int: Int] = [:]
        // [2,7,11,15]
        // 9
        for (index,value) in nums.enumerated() {
            print("\(value)")
            // 剩余得值
            let other = target - value

            if dict.keys.contains(other) {
                
                sum.append(index)
                sum.append(dict[other]!)
            }
            else {
                dict[value] = index
            }
            
        }
        return sum
    }
}
// @lc code=end

