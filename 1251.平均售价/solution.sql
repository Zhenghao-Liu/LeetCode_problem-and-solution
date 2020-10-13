# Write your MySQL query statement below
SELECT
    B.product_id,
    ROUND(SUM(B.units * A.price)/SUM(B.units),2) AS average_price
FROM
    Prices AS A
    INNER JOIN UnitsSold AS B
ON
    B.product_id=A.product_id
    AND (B.purchase_date BETWEEN A.start_date AND A.end_date)
GROUP BY
    B.product_id;
