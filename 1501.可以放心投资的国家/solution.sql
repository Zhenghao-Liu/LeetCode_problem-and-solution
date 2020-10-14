# Write your MySQL query statement below
SELECT
    A.name AS country
FROM
    Country AS A
    INNER JOIN Person AS B ON A.country_code=LEFT(B.phone_number,3)
    INNER JOIN (SELECT caller_id AS id,duration FROM Calls UNION ALL SELECT callee_id AS id,duration FROM Calls) AS C ON B.id=C.id
GROUP BY
    A.country_code
HAVING
    AVG(C.duration)>(SELECT AVG(duration) FROM Calls);
