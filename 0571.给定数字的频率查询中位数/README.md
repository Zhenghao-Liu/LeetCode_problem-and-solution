* [推荐题解](https://leetcode-cn.com/problems/find-median-given-frequency-of-numbers/solution/my-sql-bu-yong-bian-liang-li-jie-jian-dan-by-kaka_/)
* [推荐题解](https://leetcode-cn.com/problems/find-median-given-frequency-of-numbers/solution/kan-bu-dong-da-lao-men-xie-de-gen-ju-zhong-wei-shu/)

[SQL架构](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/0571.给定数字的频率查询中位数/PROBLEM.sql)

```Numbers``` 表保存数字的值及其频率。
```
+----------+-------------+
|  Number  |  Frequency  |
+----------+-------------|
|  0       |  7          |
|  1       |  1          |
|  2       |  3          |
|  3       |  1          |
+----------+-------------+
```
在此表中，数字为 ```0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3```，所以中位数是 ```(0 + 0) / 2 = 0```。
```
+--------+
| median |
+--------|
| 0.0000 |
+--------+
```
请编写一个查询来查找所有数字的中位数并将结果命名为 ```median``` 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-median-given-frequency-of-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
