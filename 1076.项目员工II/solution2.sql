# Write your MySQL query statement below
SELECT
    project_id
FROM
    Project
GROUP BY
    project_id
HAVING
    COUNT(*)>=ALL(SELECT COUNT(*) FROM Project GROUP BY project_id);
