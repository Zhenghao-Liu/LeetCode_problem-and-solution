# Write your MySQL query statement below
SELECT
    B.product_name,
    A.product_id,
    A.order_id,
    A.order_date
FROM
    Orders AS A
    INNER JOIN Products AS B
ON
    A.product_id=B.product_id
WHERE
    (A.product_id,A.order_date) IN (
        SELECT
            product_id,
            MAX(order_date)
        FROM
            Orders
        GROUP BY
            product_id
    )
ORDER BY
    B.product_name ASC,
    A.product_id ASC,
    A.order_id ASC;
