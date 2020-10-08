# Write your MySQL query statement below
SELECT
    (A.x-B.x) AS shortest
FROM
    point AS A,
    point AS B
WHERE
    A.x>B.x
ORDER BY
    shortest ASC
LIMIT
    1;
