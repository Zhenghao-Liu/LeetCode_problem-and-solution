[SQL架构](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1141.查询近30天活跃用户数/PROBLEM.sql)

活动记录表：```Activity```
```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| session_id    | int     |
| activity_date | date    |
| activity_type | enum    |
+---------------+---------+
该表是用户在社交网站的活动记录。
该表没有主键，可能包含重复数据。
activity_type 字段为以下四种值 ('open_session', 'end_session', 'scroll_down', 'send_message')。
每个 session_id 只属于一个用户。
```

请写SQL查询出截至 **2019-07-27**（包含2019-07-27），近 30天的每日活跃用户数（当天只要有一条活动记录，即为活跃用户）。

查询结果示例如下：
```
Activity table:
+---------+------------+---------------+---------------+
| user_id | session_id | activity_date | activity_type |
+---------+------------+---------------+---------------+
| 1       | 1          | 2019-07-20    | open_session  |
| 1       | 1          | 2019-07-20    | scroll_down   |
| 1       | 1          | 2019-07-20    | end_session   |
| 2       | 4          | 2019-07-20    | open_session  |
| 2       | 4          | 2019-07-21    | send_message  |
| 2       | 4          | 2019-07-21    | end_session   |
| 3       | 2          | 2019-07-21    | open_session  |
| 3       | 2          | 2019-07-21    | send_message  |
| 3       | 2          | 2019-07-21    | end_session   |
| 4       | 3          | 2019-06-25    | open_session  |
| 4       | 3          | 2019-06-25    | end_session   |
+---------+------------+---------------+---------------+

Result table:
+------------+--------------+ 
| day        | active_users |
+------------+--------------+ 
| 2019-07-20 | 2            |
| 2019-07-21 | 2            |
+------------+--------------+ 
非活跃用户的记录不需要展示。
```

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/user-activity-for-the-past-30-days-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
