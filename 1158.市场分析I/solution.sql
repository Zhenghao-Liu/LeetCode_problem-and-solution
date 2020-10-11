# Write your MySQL query statement below
SELECT
    A.user_id AS buyer_id,
    A.join_date,
    COUNT(order_date) AS orders_in_2019
FROM
    Users AS A
    LEFT OUTER JOIN (SELECT order_date,buyer_id FROM Orders WHERE YEAR(order_date)=2019) AS B
ON
    A.user_id=B.buyer_id
GROUP BY
    A.user_id
ORDER BY
    A.user_id;
