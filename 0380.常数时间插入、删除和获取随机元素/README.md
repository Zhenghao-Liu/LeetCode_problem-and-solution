* [官方题解](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/solution/chang-shu-shi-jian-cha-ru-shan-chu-he-huo-qu-sui-j/)
* [推荐题解](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/solution/fen-xiang-yi-ge-you-xiu-de-suan-fa-hashsethe-shu-z/)

设计一个支持在平均 时间复杂度 **O(1)** 下，执行以下操作的数据结构。

1. ```insert(val)```：当元素 val 不存在时，向集合中插入该项。
2. ```remove(val)```：元素 val 存在时，从集合中移除该项。
3. ```getRandom```：随机返回现有集合中的一项。每个元素应该有**相同的概率**被返回。

**示例 :**
```
// 初始化一个空的集合。
RandomizedSet randomSet = new RandomizedSet();

// 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomSet.insert(1);

// 返回 false ，表示集合中不存在 2 。
randomSet.remove(2);

// 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomSet.insert(2);

// getRandom 应随机返回 1 或 2 。
randomSet.getRandom();

// 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomSet.remove(1);

// 2 已在集合中，所以返回 false 。
randomSet.insert(2);

// 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
randomSet.getRandom();
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-delete-getrandom-o1
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
