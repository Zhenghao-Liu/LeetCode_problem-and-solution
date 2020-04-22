* [个人题解](https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/solution/ha-xi-biao-ji-he-by-lzh_yves/)

设计一个支持在平均 时间复杂度 **O(1)** 下， 执行以下操作的数据结构。

**注意: 允许出现重复元素。**

1. ```insert(val)```：向集合中插入元素 val。
2. ```remove(val)```：当 val 存在时，从集合中移除一个 val。
3. ```getRandom```：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。

**示例:**
```
// 初始化一个空的集合。
RandomizedCollection collection = new RandomizedCollection();

// 向集合中插入 1 。返回 true 表示集合不包含 1 。
collection.insert(1);

// 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
collection.insert(1);

// 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
collection.insert(2);

// getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
collection.getRandom();

// 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
collection.remove(1);

// getRandom 应有相同概率返回 1 和 2 。
collection.getRandom();
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
