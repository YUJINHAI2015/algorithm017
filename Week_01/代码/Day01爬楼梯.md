### Day01爬楼梯

https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode-solution/

```
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。

1.  1 阶 + 1 阶
2.  2 阶
```



第一种：递归算法，会超时

```
class Solution {
public:
    int climbStairs(int n) {        
        if ( n == 1 || n == 2){
            return n;   
        }
        return  climbStairs(n-1) + climbStairs(n-2);
    }
};
```



第二种：动态规划，不太懂

1、转移方程：*f*(*x*)=*f*(*x*−1)+*f*(*x*−2)

2、边界情况：f(0) = 1和f(1)=1

3、根据转移方程得到：f(2)=2，f(3)=3, f(4)=5

![fig1](https://assets.leetcode-cn.com/solution-static/70/70_fig1.gif)

```

class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};

```









