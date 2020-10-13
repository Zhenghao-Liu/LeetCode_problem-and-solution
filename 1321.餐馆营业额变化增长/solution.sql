# Write your MySQL query statement below
SELECT
    A.visited_on,
    SUM(B.amount) AS amount,
    ROUND(SUM(B.amount)/7,2) AS average_amount
FROM
    (SELECT DISTINCT visited_on FROM Customer WHERE DATEDIFF(visited_on,(SELECT MIN(visited_on) FROM Customer))>=6) AS A
    INNER JOIN Customer AS B
ON
    DATEDIFF(A.visited_on,B.visited_on) BETWEEN 0 AND 6
GROUP BY
    A.visited_on
ORDER BY
    A.visited_on;
