# Write your MySQL query statement below
SELECT
    question_id AS survey_log
FROM
    survey_log
GROUP BY
    question_id
ORDER BY
    SUM(IF(action='answer',1,0))/SUM(IF(action='show',1,0)) DESC
LIMIT
    1;
