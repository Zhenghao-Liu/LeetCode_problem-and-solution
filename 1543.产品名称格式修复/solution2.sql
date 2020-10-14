# Write your MySQL query statement below
SELECT
    product_name,
    sale_date,
    COUNT(sale_id) AS total
FROM
    (
        SELECT
            sale_id,
            LOWER(LTRIM(RTRIM(product_name))) AS product_name,
            DATE_FORMAT(sale_date,'%Y-%m') AS sale_date
        FROM
            Sales
    ) AS A
GROUP BY
    product_name,
    sale_date
ORDER BY
    product_name ASC,
    sale_date ASC;
