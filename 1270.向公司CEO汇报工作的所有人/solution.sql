# Write your MySQL query statement below
SELECT
    DISTINCT A.employee_id
FROM
    Employees AS A,
    Employees AS B,
    Employees AS C
WHERE
    A.manager_id=B.employee_id
    AND B.manager_id=C.employee_id
    AND C.manager_id=1
    AND A.employee_id!=1;
