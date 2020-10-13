# Write your MySQL query statement below
SELECT
    B.student_id,
    B.student_name,
    B.subject_name,
    COUNT(A.student_id) AS attended_exams
FROM
    Examinations AS A
    RIGHT OUTER JOIN (SELECT * FROM Students,Subjects) AS B
ON
    A.student_id=B.student_id
    AND A.subject_name=B.subject_name
GROUP BY
    B.student_id,
    B.subject_name
ORDER BY
    B.student_id,
    B.subject_name;
