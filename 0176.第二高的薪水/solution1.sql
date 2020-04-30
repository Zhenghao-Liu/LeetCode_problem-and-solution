/*
* 注意要去重因为有可能最高薪水有重复的
* 可以按照LIMIT A,B 或LIMIT B OFFSET A的方式搜索出从第[A]行开始(起始[0])的一共B行
* 但是要求没有检索时返回NULL
* 采用IFNULL(S1,S2) S1不为NULL返回S1否则返回S2
* [IFNULL ISNULL NULLIF](https://blog.csdn.net/xingyu0806/article/details/52080962)
*/
# Write your MySQL query statement below
SELECT
    IFNULL(
        (
            SELECT DISTINCT
                Salary
            FROM
                Employee
            ORDER BY
                Salary DESC
            LIMIT
                1,1
        ),
        NULL)
AS
    SecondHighestSalary;
