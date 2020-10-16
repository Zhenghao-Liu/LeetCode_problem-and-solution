# Write your MySQL query statement below
SELECT
    A.id,
    COUNT(A.id) AS num
FROM
    (   
        SELECT
            requester_id AS id
        FROM
            request_accepted
        UNION ALL
        SELECT
            accepter_id AS id
        FROM
            request_accepted
    ) AS A
GROUP BY
    A.id
ORDER BY
    num DESC
LIMIT
    1;
