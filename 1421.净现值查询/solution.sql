# Write your MySQL query statement below
SELECT
    A.id,
    A.year,
    IFNULL(B.npv,0) AS npv
FROM
    Queries AS A
    LEFT OUTER JOIN NPV AS B
ON
    A.id=B.id
    AND A.year=B.year;
