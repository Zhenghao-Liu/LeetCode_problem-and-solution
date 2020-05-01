# Write your MySQL query statement below
SELECT
    a.Score AS Score,
    (
        SELECT
            COUNT(DISTINCT b.Score)
        FROM
            Scores AS b
        WHERE
            b.Score>=a.Score
    ) AS 'Rank'
FROM
    Scores AS a
ORDER BY
    a.Score DESC
