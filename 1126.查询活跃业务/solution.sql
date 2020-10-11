# Write your MySQL query statement below
SELECT
    A.business_id
FROM
    Events AS A
    INNER JOIN (
        SELECT
            event_type,
            AVG(occurences) AS AVG_O
        FROM
            Events
        GROUP BY
            event_type
    )AS B
ON
    A.event_type=B.event_type
WHERE
    A.occurences>AVG_O
GROUP BY
    A.business_id
HAVING
    COUNT(*)>1;
