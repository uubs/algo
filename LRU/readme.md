# ALGO

## LRU
LRU是一种缓存淘汰策略

当缓存放满了，我们应该替换哪一块缓存？

LRU认为我们最近使用过的数据是有用的，而很久之前使用的数据是没用的，可以用来替换。

LRU是按照访问的时序来淘汰页面的

## 实现LRU
缓存的大小
放入缓存 O(1)
从缓存中取出 O(1)

### 对缓存的要求
查找快，插入快，删除快，有顺序之分

哈系表：查找快，但数据没有固定顺序
链表： 有顺序i，插入快，删除快，但查找慢

哈系表+链表 = 哈系链表





## LFU
LRU是一种缓存淘汰策略

LFU是按照访问的频率来淘汰页面的

