# Write your MySQL query statement below
SELECT
    stock_name,
    SUM(
        CASE operation
            WHEN 'Buy' THEN -price
            WHEN 'Sell' THEN price
        END
    ) AS capital_gain_loss
FROM
    Stocks
GROUP BY
    stock_name;
