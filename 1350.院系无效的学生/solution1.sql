# Write your MySQL query statement below
SELECT
    A.id,A.name
FROM
    Students AS A LEFT OUTER JOIN Departments AS B
ON
    A.department_id=B.id
WHERE
    B.id IS NULL;
