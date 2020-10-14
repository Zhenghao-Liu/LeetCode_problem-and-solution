# Write your MySQL query statement below
SELECT
    B.item_category AS Category,
    SUM(IF(DATE_FORMAT(A.order_date,'%w')=1,quantity,0)) AS Monday,
    SUM(IF(DATE_FORMAT(A.order_date,'%w')=2,quantity,0)) AS Tuesday,
    SUM(IF(DATE_FORMAT(A.order_date,'%w')=3,quantity,0)) AS Wednesday,
    SUM(IF(DATE_FORMAT(A.order_date,'%w')=4,quantity,0)) AS Thursday,
    SUM(IF(DATE_FORMAT(A.order_date,'%w')=5,quantity,0)) AS Friday,
    SUM(IF(DATE_FORMAT(A.order_date,'%w')=6,quantity,0)) AS Saturday,
    SUM(IF(DATE_FORMAT(A.order_date,'%w')=0,quantity,0)) AS Sunday
FROM
    Orders AS A
    RIGHT OUTER JOIN Items AS B
ON
    A.item_id=B.item_id
GROUP BY
    B.item_category
ORDER BY
    B.item_category ASC;
