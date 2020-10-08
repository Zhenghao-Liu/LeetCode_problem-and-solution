# Write your MySQL query statement below
SELECT
    A.project_id,
    A.employee_id
FROM
    Project AS A
    INNER JOIN Employee AS B
ON
    A.employee_id=B.employee_id
WHERE
    (A.project_id,B.experience_years) IN (
        SELECT
            C.project_id,
            MAX(D.experience_years)
        FROM
            Project AS C
            INNER JOIN Employee AS D
        ON
            C.employee_id=D.employee_id
        GROUP BY
            C.project_id
    );
