# Write your MySQL query statement below
SELECT
    A.customer_id,
    A.name
FROM
    Customers AS A
    INNER JOIN Orders AS B ON A.customer_id=B.customer_id
    INNER JOIN Product AS C ON B.product_id=C.product_id
WHERE
    YEAR(B.order_date)=2020
    AND (MONTH(B.order_date)=6 OR MONTH(B.order_date)=7)
GROUP BY
    B.customer_id
HAVING
    SUM(IF(MONTH(B.order_date)=6,B.quantity*C.price,0))>=100
    AND SUM(IF(MONTH(B.order_date)=7,B.quantity*C.price,0))>=100;
