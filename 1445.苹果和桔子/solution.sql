# Write your MySQL query statement below
SELECT sale_date, 
    SUM(
        CASE fruit
            WHEN 'apples' THEN sold_num 
            WHEN 'oranges' THEN -sold_num 
        END
    ) AS diff
FROM
    Sales
GROUP BY
    sale_date
ORDER BY
    sale_date;
