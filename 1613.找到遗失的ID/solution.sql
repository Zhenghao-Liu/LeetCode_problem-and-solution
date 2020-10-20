# Write your MySQL query statement below
WITH T1 AS (
    SELECT 0 AS n
    UNION SELECT 1
    UNION SELECT 2
    UNION SELECT 3
    UNION SELECT 4
    UNION SELECT 5
    UNION SELECT 6
    UNION SELECT 7
    UNION SELECT 8
    UNION SELECT 9
),
T2 AS (
    SELECT
        A.n*10+1*B.n+1 AS n
    FROM
        T1 AS A,T1 AS B
    ORDER BY
        n
)

SELECT
    n AS ids
FROM
    T2
WHERE
    n<(SELECT MAX(customer_id) FROM Customers)
    AND n NOT IN (SELECT customer_id FROM Customers)
ORDER BY
    ids ASC;
