# Write your MySQL query statemen
SELECT
    A.gender,
    A.day,
    SUM(B.score_points) AS total
FROM
    Scores AS A
    INNER JOIN Scores AS B
ON
    A.gender=B.gender
    AND A.day>=B.day
GROUP BY
    A.gender,
    A.day
ORDER BY
    A.gender,
    A.day;
