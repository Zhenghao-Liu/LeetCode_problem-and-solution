[SQL架构](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1607.没有卖出的卖家/PROBLEM.sql)

表: ```Customer```
```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| customer_name | varchar |
+---------------+---------+
customer_id 是该表主键.
该表的每行包含网上商城的每一位顾客的信息.
```

表: ```Orders```
```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| sale_date     | date    |
| order_cost    | int     |
| customer_id   | int     |
| seller_id     | int     |
+---------------+---------+
order_id 是该表主键.
该表的每行包含网上商城的所有订单的信息.
sale_date 是顾客customer_id和卖家seller_id之间交易的日期.
```

表: ```Seller```
```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| seller_id     | int     |
| seller_name   | varchar |
+---------------+---------+
seller_id 是该表主键.
该表的每行包含每一位卖家的信息.
```

写一个SQL语句, 报告所有在2020年度没有任何卖出的卖家的名字.

返回结果按照 seller_name **升序排列**.

查询结果格式如下例所示.

 
```
Customer 表:
+--------------+---------------+
| customer_id  | customer_name |
+--------------+---------------+
| 101          | Alice         |
| 102          | Bob           |
| 103          | Charlie       |
+--------------+---------------+

Orders 表:
+-------------+------------+--------------+-------------+-------------+
| order_id    | sale_date  | order_cost   | customer_id | seller_id   |
+-------------+------------+--------------+-------------+-------------+
| 1           | 2020-03-01 | 1500         | 101         | 1           |
| 2           | 2020-05-25 | 2400         | 102         | 2           |
| 3           | 2019-05-25 | 800          | 101         | 3           |
| 4           | 2020-09-13 | 1000         | 103         | 2           |
| 5           | 2019-02-11 | 700          | 101         | 2           |
+-------------+------------+--------------+-------------+-------------+

Seller 表:
+-------------+-------------+
| seller_id   | seller_name |
+-------------+-------------+
| 1           | Daniel      |
| 2           | Elizabeth   |
| 3           | Frank       |
+-------------+-------------+

Result 表:
+-------------+
| seller_name |
+-------------+
| Frank       |
+-------------+
Daniel在2020年3月卖出1次.
Elizabeth在2020年卖出2次, 在2019年卖出1次.
Frank在2019年卖出1次, 在2020年没有卖出.
```

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sellers-with-no-sales
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
