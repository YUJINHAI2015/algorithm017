### **动态规划**

1、最优子结构（重复性）

2、存储中间状态

3、递推公式（自底向上）



- Fibonacci 数列（一维）

1、先递归分治和记忆化搜索

2、递推



- 路径计数（二维）

 维度变化和取舍

 1、用分治的想法找到一个子问题

 2、递推

---





## **从斐波拉数列中我们用递归解决**

F(n) = F(n-1) + F(n-2);

其实这个是一维结构，画出斐波拉数列图

初始代码

``` 

class Solution {

​	public:

  int fib(int N) {

​    if(N == 1 || N == 0) return N;

​    return fib(N-1)+fib(N-2);

  }

};

```

存储中间状态：

```

class Solution {

public:

  int fib(int N) {

​    vector<int> cache(N + 1, 0);

​    return helper(cache, N);

  }

  int helper(vector<int> cache, int N) {

​    if (N<2) return N;

​    if (cache[N])return cache[N];

​    cache[N] = helper(cache,N-1) + helper(cache,N-2);

​    return cache[N];

  }

};

```



上面两种方式都是自顶向下的做法

如果要得到递推公式，就要从底部开始计算

从图中可以看出

f(2)=f(1)+f(0)

f(3)=f(2)+f(1)

f(4)=f(3)+f(2)

所以得到

```

 class Solution {

public:

  int fib(int N) {

​    if (N <= 1) {

​      return N;

​    }

​    if (N == 2) {

​      return 1;

​    }     

​    int i = 0;

​    int j = 1;

​    int res = 1;

​    for(int k = 3; k <= N; k++) {

​      i = j;

​      j = res;

​      res = i + j;

​    }

​    return res;

  }

};



```



### **不同路径**

https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-by-powcai-2/

也可以用相似的方式得到递推公式

1、找出递归

``` 

 public int uniquePaths(int m, int n) {

  return uniquePathsHelper(1, 1, m, n);

}

//第i行第j列到第m行第n列共有多少种路径

public int uniquePathsHelper(int i, int j, int m, int n) {

  //边界条件的判断

  if (i > m || j > n)

​    return 0;

  if ((i == m && j == n))

​    return 1;

  //从右边走有多少条路径

  int right = uniquePathsHelper(i + 1, j, m, n);

  //从下边走有多少条路径

  int down = uniquePathsHelper(i, j + 1, m, n);

  //返回总的路径

  return right + down;

}

```



添加记忆化搜索

```

 public int uniquePaths(int m, int n) {

  return uniquePathsHelper(1, 1, m, n, new HashMap<>());

}


public int uniquePathsHelper(int i, int j, int m, int n, Map<String, Integer> map) {

  if (i > m || j > n)

​    return 0;

  if ((i == m && j == n))

​    return 1;

  String key = i + "*" + j;

  if (map.containsKey(key))

​    return map.get(key);

  int right = uniquePathsHelper(i + 1, j, m, n, map);

  int down = uniquePathsHelper(i, j + 1, m, n, map);

  int totla = right + down;

  map.put(key, totla);

  return totla;

}

```



自底向上推导出递推公式

```

 public int uniquePaths(int m, int n) {

  int[] dp = new int[m];

  Arrays.fill(dp, 1);

  for (int j = 1; j < n; j++)

​    for (int i = 1; i < m; i++)

​      dp[i] += dp[i - 1];

  return dp[m - 1];

}
```