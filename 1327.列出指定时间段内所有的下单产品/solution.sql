# Write your MySQL query statement below
SELECT
    A.product_name,
    SUM(B.unit) AS unit
FROM
    Products AS A
    INNER JOIN Orders AS B
ON
    A.product_id=B.product_id
WHERE
    YEAR(B.order_date)=2020
    AND MONTH(B.order_date)=2
GROUP BY
    A.product_id
HAVING
    SUM(B.unit)>=100;

