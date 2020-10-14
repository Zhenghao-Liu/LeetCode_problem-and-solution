# Write your MySQL query statement below
SELECT
    A.name AS warehouse_name,
    SUM(A.units*B.Width*B.Length*B.Height) AS volume
FROM
    Warehouse AS A
    INNER JOIN Products AS B
ON
    A.product_id=B.product_id
GROUP BY
    A.name;
