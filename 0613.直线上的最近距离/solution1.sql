# Write your MySQL query statement below
SELECT
    MIN(ABS(A.x-B.x)) AS shortest
FROM
    point AS A,
    point AS B
WHERE
    A.x!=B.x;
