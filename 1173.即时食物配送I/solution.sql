# Write your MySQL query statement below
SELECT
    ROUND((SELECT COUNT(*) FROM Delivery WHERE order_date=customer_pref_delivery_date)/(COUNT(*))*100,2) AS immediate_percentage
FROM
    Delivery;
