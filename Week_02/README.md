学习笔记

好文章：https://mp.weixin.qq.com/s/JWmTeC7aKbBfGx4TY6uwuQ

Leetcode 递归模块：https://leetcode-cn.com/leetbook/detail/recursion/

### 二叉树递归遍历

#### 递归三要素

1、确定传参和返回值

2、确定终止条件

3、确定每一次要处理的信息（最小重复子问题）



习题：

- 589 . N叉树的前序遍历
- 590 . N叉树的后序遍历



### 二叉树迭代遍历

#### 用栈实现递归

主要是注意加入栈的顺序。

前序遍历伪代码：

```
1、根节点入栈
2、while 栈有节点 {
	3、弹出栈顶
	if 有值，记录到数组中
	else 没值 continue
	
	4、右子树入栈
	5、左子树入栈
}

```























