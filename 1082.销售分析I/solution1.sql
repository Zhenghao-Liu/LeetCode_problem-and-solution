# Write your MySQL query statement below
SELECT
    seller_id
FROM
    Sales
GROUP BY
    seller_id
HAVING
    SUM(price)=(
        SELECT
            SUM(price) as A
        FROM
            Sales
        GROUP BY
            seller_id
        ORDER BY
            A DESC
        limit
            1
    );
