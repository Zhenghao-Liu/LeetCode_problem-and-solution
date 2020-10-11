# Write your MySQL query statement below
SELECT
    A.person_name
FROM
    Queue AS A
    INNER JOIN (SELECT person_id,SUM(weight) OVER (ORDER BY turn ASC) AS SUM_W FROM Queue) AS B
ON
    A.person_id=B.person_id
WHERE
    SUM_W<=1000
ORDER BY
    A.turn DESC
LIMIT
    1;
