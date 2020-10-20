[SQL架构](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1613.找到遗失的ID/PROBLEM.sql)

表: ```Customers```
```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| customer_name | varchar |
+---------------+---------+
customer_id 是该表主键.
该表第一行包含了顾客的名字和id.
```

写一个 SQL 语句, 找到所有遗失的顾客id. 遗失的顾客id是指那些不在 ```Customers``` 表中, 值却处于 1 和表中**最大** ```customer_id``` 之间的id.

**注意**: 最大的 ```customer_id``` 值不会超过 ```100```.

返回结果按 ```ids``` **升序**排列

查询结果格式如下例所示.

 
```
Customer 表:
+-------------+---------------+
| customer_id | customer_name |
+-------------+---------------+
| 1           | Alice         |
| 4           | Bob           |
| 5           | Charlie       |
+-------------+---------------+

Result 表:
+-----+
| ids |
+-----+
| 2   |
| 3   |
+-----+
表中最大的customer_id是5, 所以在范围[1,5]内, ID2和3从表中遗失.
```

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-missing-ids
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
