# Write your MySQL query statement below
SELECT
    B.product_name,A.year,A.price
FROM
    Sales AS A,
    Product AS B
WHERE
    A.product_id=B.product_id;
