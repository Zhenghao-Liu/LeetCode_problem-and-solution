# Write your MySQL query statement below
SELECT
    ROUND(MIN(SQRT((B.y-A.y)*(B.y-A.y)+(B.x-A.x)*(B.x-A.x))),2) AS shortest
FROM
    point_2d AS A,
    point_2d AS B
WHERE
    NOT(B.x=A.x AND B.y=A.y);
