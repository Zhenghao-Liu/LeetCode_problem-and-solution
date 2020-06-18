#注意：学生在每个课中不应被重复计算。
# Write your MySQL query statement below
SELECT
    class
FROM
    courses
GROUP BY
    class
HAVING
    COUNT(DISTINCT(student))>=5;
