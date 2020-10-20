# Write your MySQL query statement below
SELECT
    B.seller_name
FROM
    (SELECT DISTINCT seller_id FROM Orders WHERE YEAR(sale_date)=2020) AS A
    RIGHT OUTER JOIN Seller AS B
ON
    A.seller_id=B.seller_id
WHERE
    A.seller_id IS NULL
ORDER BY
    B.seller_name ASC;
