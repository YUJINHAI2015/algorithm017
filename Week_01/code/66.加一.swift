/*
 * @lc app=leetcode.cn id=66 lang=swift
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
    func plusOne(_ digits: [Int]) -> [Int] {

        var len: Int = digits.count
        var digits = digits

        while len > 0{
            len -= 1
            digits[len] += 1
            digits[len] %= 10
            if digits[len] != 0 {
                return digits
            }
        }

        var other: [Int] = []
        other.append(1)
        other.append(contentsOf: digits)
        digits = other
        return digits
        
    }

}
// @lc code=end

