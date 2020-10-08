# Write your MySQL query statement below
SELECT
    A.dept_name,
    COUNT(B.student_id) AS student_number
FROM
    department AS A
    LEFT OUTER JOIN student AS B
ON
    A.dept_id=B.dept_id
GROUP BY
    A.dept_name
ORDER BY
    student_number DESC,
    dept_name ASC;
