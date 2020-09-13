不使用任何内建的哈希表库设计一个哈希集合

具体地说，你的设计应该包含以下的功能

* ```add(value)```：向哈希集合中插入一个值。
* ```contains(value)``` ：返回哈希集合中是否存在这个值。
* ```remove(value)```：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

**示例:**
```
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // 返回 true
hashSet.contains(3);    // 返回 false (未找到)
hashSet.add(2);          
hashSet.contains(2);    // 返回 true
hashSet.remove(2);          
hashSet.contains(2);    // 返回  false (已经被删除)
```

**注意：**

* 所有的值都在 ```[0, 1000000]```的范围内。
* 操作的总数目在```[1, 10000]```范围内。
* 不要使用内建的哈希集合库。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-hashset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
