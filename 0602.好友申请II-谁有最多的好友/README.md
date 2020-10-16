[SQL架构](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/0602.好友申请II:谁有最多的好友/PROBLEM.sql)

在 Facebook 或者 Twitter 这样的社交应用中，人们经常会发好友申请也会收到其他人的好友申请。

 

表 ```request_accepted``` 存储了所有好友申请通过的数据记录，其中， **requester_id** 和 **accepter_id** 都是用户的编号。

 
```
| requester_id | accepter_id | accept_date|
|--------------|-------------|------------|
| 1            | 2           | 2016_06-03 |
| 1            | 3           | 2016-06-08 |
| 2            | 3           | 2016-06-08 |
| 3            | 4           | 2016-06-09 |
```
写一个查询语句，求出谁拥有最多的好友和他拥有的好友数目。对于上面的样例数据，结果为：
```
| id | num |
|----|-----|
| 3  | 3   |
```
**注意：**

* 保证拥有最多好友数目的只有 1 个人。
* 好友申请只会被接受一次，所以不会有 ```requester_id``` 和 ```accepter_id``` 值都相同的重复记录。
 

**解释：**

编号为 '3' 的人是编号为 '1'，'2' 和 '4' 的好友，所以他总共有 3 个好友，比其他人都多。

 

**进阶：**

在真实世界里，可能会有多个人拥有好友数相同且最多，你能找到所有这些人吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/friend-requests-ii-who-has-the-most-friends
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
