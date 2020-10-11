# Write your MySQL query statement below
SELECT
    ROUND(AVG(IF(A.order_date=A.customer_pref_delivery_date,1,0))*100,2) AS immediate_percentage
FROM
    Delivery AS A
    RIGHT OUTER JOIN (SELECT customer_id,MIN(order_date) AS first_date FROM Delivery GROUP BY customer_id) AS B
ON
    A.customer_id=B.customer_id
    AND A.order_date=B.first_date;
