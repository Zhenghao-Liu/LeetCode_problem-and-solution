* [B站讲解线段树](https://www.bilibili.com/video/BV1cb411t7AM/)
* [B站讲解树状数组](https://www.bilibili.com/video/BV1pE41197Qj/)

给定一个整数数组  *nums*，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

*update(i, val)* 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。

**示例:**
```
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
```
**说明:**

1. 数组仅可以在 update 函数下进行修改。
2. 你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-mutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
