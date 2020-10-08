# Write your MySQL query statement below
SELECT
    A.customer_id
FROM
    Customer AS A
    RIGHT OUTER JOIN Product AS B
ON
    A.product_key=B.product_key
GROUP BY
    A.customer_id
HAVING
    COUNT(DISTINCT A.product_key)=(SELECT COUNT(*) FROM Product);
