# Write your MySQL query statement below
SELECT
    A.product_id,
    B.product_name
FROM
    (
        SELECT
            DISTINCT product_id
        FROM
            Sales
        WHERE
            sale_date BETWEEN '2019-01-01' AND '2019-03-31'
            AND product_id NOT IN (SELECT DISTINCT product_id FROM Sales WHERE sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31')
    ) AS A
    INNER JOIN Product AS B
ON
    A.product_id=B.product_id;
