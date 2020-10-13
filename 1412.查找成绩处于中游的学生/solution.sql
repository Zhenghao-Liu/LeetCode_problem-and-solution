# Write your MySQL query statement below
SELECT
    DISTINCT A.student_id,
    A.student_name
FROM
    Student AS A
    RIGHT OUTER JOIN Exam AS B
ON
    A.student_id=B.student_id
WHERE
    A.student_id NOT IN (
        SELECT
            student_id
        FROM
            Exam
        WHERE
            (exam_id,score) IN (
                SELECT exam_id,MAX(score) FROM Exam GROUP BY exam_id
                UNION ALL
                SELECT exam_id,MIN(score) FROM Exam GROUP BY exam_id
            )
    )
ORDER BY
    A.student_id;
