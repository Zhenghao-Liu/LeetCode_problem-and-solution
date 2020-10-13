# Write your MySQL query statement below
SELECT
    A.product_id,
    B.product_name,
    A.report_year,
    SUM(A.total_amount) AS total_amount
FROM
    (
        SELECT
            product_id,
            '2018' AS report_year,
            (DATEDIFF(
                IF(YEAR(period_end)>2018,'2018-12-31',period_end),
                IF(YEAR(period_start)<2018,'2018-01-01',period_start)
            )+1)*average_daily_sales AS total_amount
        FROM
            Sales
        GROUP BY
            product_id
        HAVING
            total_amount>0

        UNION ALL

        SELECT
            product_id,
            '2019' AS report_year,
            (DATEDIFF(
                IF(YEAR(period_end)>2019,'2019-12-31',period_end),
                IF(YEAR(period_start)<2019,'2019-01-01',period_start)
            )+1)*average_daily_sales AS total_amount
        FROM
            Sales
        GROUP BY
            product_id
        HAVING
            total_amount>0

        UNION ALL

        SELECT
            product_id,
            '2020' AS report_year,
            (DATEDIFF(
                IF(YEAR(period_end)>2020,'2020-12-31',period_end),
                IF(YEAR(period_start)<2020,'2020-01-01',period_start)
            )+1)*average_daily_sales AS total_amount
        FROM
            Sales
        GROUP BY
            product_id
        HAVING
            total_amount>0
    ) AS A
    LEFT OUTER JOIN Product AS B
ON
    A.product_id=B.product_id
GROUP BY
    A.product_id,
    A.report_year
ORDER BY
    A.product_id,
    A.report_year;
