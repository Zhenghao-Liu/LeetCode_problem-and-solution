# Write your MySQL query statement below
SELECT
    A.product_id,
    B.product_name
FROM
    Sales AS A
    INNER JOIN Product AS B
ON
    A.product_id=B.product_id
GROUP BY
    A.product_id
HAVING
    SUM(IF(A.sale_date BETWEEN '2019-01-01' AND '2019-03-31',1,0))>0
    AND SUM(IF(A.sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31',1,0))=0;
