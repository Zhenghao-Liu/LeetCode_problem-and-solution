# Write your MySQL query statement below
SELECT
    A.name AS customer_name,
    A.customer_id,
    B.order_id,
    B.order_date
FROM
    Customers AS A
    LEFT OUTER JOIN (
        SELECT
            order_id,
            order_date,
            customer_id,
            ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date DESC) AS rank_c
        FROM
            Orders
    ) AS B
ON
    A.customer_id=B.customer_id
WHERE
    rank_c<=3
ORDER BY
    customer_name ASC,
    a.customer_id ASC,
    B.order_date DESC;
