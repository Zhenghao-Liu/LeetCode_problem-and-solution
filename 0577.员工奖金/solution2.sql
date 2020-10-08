# Write your MySQL query statement below
SELECT
    A.name,
    B.bonus
FROM
    Employee AS A
    LEFT OUTER JOIN Bonus AS B
ON
    A.empId=B.empId
WHERE
    IFNULL(B.bonus,0)<1000;
