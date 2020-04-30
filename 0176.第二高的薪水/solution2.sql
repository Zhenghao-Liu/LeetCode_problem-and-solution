/*
* 注意要去重因为有可能最高薪水有重复的
* 可以按照LIMIT A,B 或LIMIT B OFFSET A的方式搜索出从第[A]行开始(起始[0])的一共B行
* 但是要求没有检索时返回NULL
* 可以将当前搜索结果当做一个临时表，结果就变成了SELECT (临时表),即SELECT NULL 
*/
# Write your MySQL query statement below
SELECT
(
    SELECT DISTINCT
        Salary
    FROM
        Employee
    ORDER BY
        Salary DESC
    LIMIT
        1,1
)
AS
    SecondHighestSalary;
