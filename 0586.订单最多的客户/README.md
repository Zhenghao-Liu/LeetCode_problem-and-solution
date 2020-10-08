[SQL架构](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/0586.订单最多的客户/PROBLEM.sql)

在表 **orders** 中找到订单数最多客户对应的 **customer_number** 。

数据保证订单数最多的顾客恰好只有一位。

表 **orders** 定义如下：
```
| Column            | Type      |
|-------------------|-----------|
| order_number (PK) | int       |
| customer_number   | int       |
| order_date        | date      |
| required_date     | date      |
| shipped_date      | date      |
| status            | char(15)  |
| comment           | char(200) |
```
**样例输入**
```
| order_number | customer_number | order_date | required_date | shipped_date | status | comment |
|--------------|-----------------|------------|---------------|--------------|--------|---------|
| 1            | 1               | 2017-04-09 | 2017-04-13    | 2017-04-12   | Closed |         |
| 2            | 2               | 2017-04-15 | 2017-04-20    | 2017-04-18   | Closed |         |
| 3            | 3               | 2017-04-16 | 2017-04-25    | 2017-04-20   | Closed |         |
| 4            | 3               | 2017-04-18 | 2017-04-28    | 2017-04-25   | Closed |         |
```
**样例输出**
```
| customer_number |
|-----------------|
| 3               |
```
**解释**
```
customer_number 为 '3' 的顾客有两个订单，比顾客 '1' 或者 '2' 都要多，因为他们只有一个订单
所以结果是该顾客的 customer_number ，也就是 3 。
```
**进阶**： *如果有多位顾客订单数并列最多，你能找到他们所有的 customer_number 吗？*

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/customer-placing-the-largest-number-of-orders
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
