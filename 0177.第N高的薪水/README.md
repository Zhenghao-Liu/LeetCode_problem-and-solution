* [推荐题解](https://leetcode-cn.com/problems/nth-highest-salary/solution/mysql-zi-ding-yi-bian-liang-by-luanz/)

编写一个 SQL 查询，获取 ```Employee``` 表中第 *n* 高的薪水（Salary）。
```
+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
```
例如上述 ```Employee``` 表，*n = 2* 时，应返回第二高的薪水 ```200```。如果不存在第 *n* 高的薪水，那么查询应返回 ```null```。
```
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nth-highest-salary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
