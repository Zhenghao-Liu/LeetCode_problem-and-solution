# Write your MySQL query statement below
SELECT
    A.username,
    A.activity,
    A.startDate,
    A.endDate
FROM
    UserActivity AS A
    INNER JOIN UserActivity AS B
ON
    A.username=B.username
GROUP BY
    A.username,
    A.startDate
HAVING
    SUM(IF(B.startDate>A.startDate,1,0))=1 OR COUNT(*)=1;
