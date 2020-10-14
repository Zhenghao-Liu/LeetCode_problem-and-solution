# Write your MySQL query statement below
SELECT
    A.customer_id,
    A.product_id,
    B.product_name
FROM
    Orders AS A
    LEFT OUTER JOIN Products AS B
ON
    A.product_id=B.product_id
GROUP BY
    A.customer_id,
    A.product_id
HAVING
    (A.customer_id,COUNT(*)) IN (
        SELECT
            customer_id,
            MAX(rank_c)
        FROM
            (
                SELECT
                    customer_id,
                    COUNT(*) AS rank_c
                FROM
                    Orders
                GROUP BY
                    customer_id,
                    product_id
            ) AS D
        GROUP BY
            customer_id
    )
ORDER BY
    A.customer_id ASC,
    A.product_id ASC;
