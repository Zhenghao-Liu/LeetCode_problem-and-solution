* [官方题解](https://leetcode-cn.com/problems/reach-a-number/solution/dao-da-zhong-dian-shu-zi-by-leetcode/)

在一根无限长的数轴上，你站在```0```的位置。终点在```target```的位置。

每次你可以选择向左或向右移动。第 n 次移动（从 1 开始），可以走 n 步。

返回到达终点需要的最小移动次数。

**示例 1:**
```
输入: target = 3
输出: 2
解释:
第一次移动，从 0 到 1 。
第二次移动，从 1 到 3 。
```
**示例 2:**
```
输入: target = 2
输出: 3
解释:
第一次移动，从 0 到 1 。
第二次移动，从 1 到 -1 。
第三次移动，从 -1 到 2 。
```
**注意:**

* ```target```是在```[-10^9, 10^9]```范围中的非零整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reach-a-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
