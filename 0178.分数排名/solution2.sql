# Write your MySQL query statement below
SELECT
    a.Score AS Score,
    COUNT(DISTINCT(b.Score)) AS 'Rank'
FROM
    Scores AS a,
    Scores AS b
WHERE
    a.Score<=b.Score
GROUP BY
    a.Id
ORDER BY
    a.Score DESC
