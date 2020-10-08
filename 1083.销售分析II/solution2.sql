# Write your MySQL query statement below
SELECT
    A.buyer_id
FROM
    Sales AS A
    INNER JOIN Product AS B
ON
    A.product_id=B.product_id
GROUP BY
    A.buyer_id
HAVING
    SUM(IF(B.product_name='S8',1,0))>0
    AND SUM(IF(B.product_name='iphone',1,0))=0;
