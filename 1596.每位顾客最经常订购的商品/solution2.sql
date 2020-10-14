# Write your MySQL query statement below
SELECT
    B.customer_id,
    B.product_id,
    C.product_name
FROM
    (
        SELECT
            customer_id,
            product_id,
            DENSE_RANK() OVER (PARTITION BY customer_id ORDER BY cnt DESC) AS rank_c
        FROM
            (
                SELECT
                    customer_id,
                    product_id,
                    COUNT(*) AS cnt
                FROM
                    Orders
                GROUP BY
                    customer_id,
                    product_id
            ) AS A
    ) AS B
    LEFT OUTER JOIN Products AS C
ON
    B.product_id=C.product_id
WHERE
    B.rank_c=1;
