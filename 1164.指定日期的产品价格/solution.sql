# Write your MySQL query statement below
SELECT
    A.product_id,
    IFNULL(B.new_price,10) AS price
FROM
    (SELECT DISTINCT product_id FROM Products) AS A
    LEFT OUTER JOIN (
        SELECT
            product_id,
            new_price
        FROM
            Products
        WHERE
            (product_id,change_date) IN (SELECT product_id,MAX(change_date) FROM Products WHERE change_date<='2019-08-16' GROUP BY product_id)
    ) AS B
ON
    A.product_id=B.product_id;
