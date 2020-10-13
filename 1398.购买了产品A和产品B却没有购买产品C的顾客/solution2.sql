# Write your MySQL query statement below
SELECT
    A.customer_id,
    B.customer_name
FROM
    Orders AS A,
    Customers AS B
WHERE
    A.customer_id=B.customer_id
GROUP BY
    A.customer_id
HAVING
    SUM(A.product_name='A') >0
    AND SUM(A.product_name='B') >0
    AND SUM(A.product_name='C') =0
ORDER BY
    A.customer_id;
