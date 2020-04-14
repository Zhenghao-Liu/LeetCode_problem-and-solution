* [推荐题解](https://leetcode-cn.com/problems/largest-divisible-subset/solution/ge-ren-ti-jie-dpcon2-by-leolee/)

给出一个由**无重复的**正整数组成的集合，找出其中最大的整除子集，子集中任意一对 (Si，Sj) 都要满足：Si % Sj = 0 或 Sj % Si = 0。

如果有多个目标子集，返回其中任何一个均可。

**示例 1:**
```
输入: [1,2,3]
输出: [1,2] (当然, [1,3] 也正确)
```
**示例 2:**
```
输入: [1,2,4,8]
输出: [1,2,4,8]
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-divisible-subset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
