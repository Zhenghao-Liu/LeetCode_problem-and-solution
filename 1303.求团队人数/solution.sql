# Write your MySQL query statement below
SELECT
    A.employee_id,
    C.team_size
FROM
    Employee AS A,
    (SELECT team_id,COUNT(*) AS team_size FROM Employee GROUP BY team_id) AS C
WHERE
    A.team_id=C.team_id;
