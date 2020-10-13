# Write your MySQL query statement below
SELECT
    A.customer_id,
    B.customer_name
FROM
    (
        SELECT
            DISTINCT customer_id
        FROM
            Orders
        WHERE
            customer_id IN (SELECT customer_id FROM Orders WHERE product_name='A')
            AND customer_id IN (SELECT customer_id FROM Orders WHERE product_name='B')
            AND customer_id NOT IN (SELECT customer_id FROM Orders WHERE product_name='C')
    ) AS A,
    Customers AS B
WHERE
    A.customer_id=B.customer_id
ORDER BY
    A.customer_id;
