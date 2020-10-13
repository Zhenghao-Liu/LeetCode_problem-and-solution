[SQL架构](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1440.计算布尔表达式的值/PROBLEM.sql)

表 ```Variables```:
```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| name          | varchar |
| value         | int     |
+---------------+---------+
name 是该表主键.
该表包含了存储的变量及其对应的值.
```

表 ```Expressions```:
```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| left_operand  | varchar |
| operator      | enum    |
| right_operand | varchar |
+---------------+---------+
(left_operand, operator, right_operand) 是该表主键.
该表包含了需要计算的布尔表达式.
operator 是枚举类型, 取值于('<', '>', '=')
left_operand 和 right_operand 的值保证存在于 Variables 表单中.
```

写一个 SQL 查询,  以计算表 ```Expressions``` 中的布尔表达式.

返回的结果表没有顺序要求.

查询结果格式如下例所示.
```
Variables 表:
+------+-------+
| name | value |
+------+-------+
| x    | 66    |
| y    | 77    |
+------+-------+

Expressions 表:
+--------------+----------+---------------+
| left_operand | operator | right_operand |
+--------------+----------+---------------+
| x            | >        | y             |
| x            | <        | y             |
| x            | =        | y             |
| y            | >        | x             |
| y            | <        | x             |
| x            | =        | x             |
+--------------+----------+---------------+

Result 表:
+--------------+----------+---------------+-------+
| left_operand | operator | right_operand | value |
+--------------+----------+---------------+-------+
| x            | >        | y             | false |
| x            | <        | y             | true  |
| x            | =        | y             | false |
| y            | >        | x             | true  |
| y            | <        | x             | false |
| x            | =        | x             | true  |
+--------------+----------+---------------+-------+
如上所示, 你需要通过使用 Variables 表来找到 Expressions 表中的每一个布尔表达式的值.
```

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-boolean-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
