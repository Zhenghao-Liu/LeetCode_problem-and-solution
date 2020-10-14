# Write your MySQL query statement below
SELECT
    A.id AS p1,
    B.id AS p2,
    ABS(A.x_value-B.x_value)*ABS(A.y_value-B.y_value) AS area
FROM
    Points AS A
    INNER JOIN Points AS B
ON
    A.id<B.id
WHERE
    A.x_value!=B.x_value
    AND A.y_value!=B.y_value
ORDER BY
    area DESC,
    p1 ASC,
    p2 ASC;
