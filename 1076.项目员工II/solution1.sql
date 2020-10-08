# Write your MySQL query statement below
SELECT
    project_id
FROM
    Project
GROUP BY
    project_id
HAVING
    COUNT(*)=(
        SELECT
            COUNT(*) AS CNT
        FROM
            Project
        GROUP BY
            project_id
        ORDER BY
            CNT DESC
        LIMIT 1
    );
