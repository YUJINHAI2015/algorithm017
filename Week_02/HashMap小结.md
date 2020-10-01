### HashMap小结



https://developer.apple.com/documentation/swift/hashable

https://swifter.tips/hash/

https://useyourloaf.com/blog/swift-hashable/

哈希函数---》减少碰撞

Swift 中大部分类型都实现了Hashable协议，

字符串，整数，浮点数和布尔值，甚至集合在默认情况下都是可哈希的。

#### 为什么要使用hash，在什么情况下使用？

当你在集合中使用自己自定义的类型，或者将其用作字典的键类型的时候，要实现Hashable协议。

#### 哪些类实现了hash

1、在swift中，NSObject及其子类默认实现了Hashable

2、非NSObject类我们需要遵循Hashable,并根据==操作符的内容给出哈希算法。



