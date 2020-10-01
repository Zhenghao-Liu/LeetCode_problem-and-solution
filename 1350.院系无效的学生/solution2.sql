# Write your MySQL query statement below
SELECT
    A.id,A.name
FROM
    Students AS A
WHERE
    A.department_id NOT IN (SELECT B.id FROM Departments AS B);
