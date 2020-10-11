# Write your MySQL query statement below
SELECT
    ROUND(AVG(IF(order_date=customer_pref_delivery_date,1,0))*100,2) AS immediate_percentage
FROM
    Delivery
WHERE
    (customer_id,order_date) IN (SELECT customer_id,MIN(order_date) AS order_date FROM Delivery GROUP BY customer_id);
