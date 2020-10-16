# Write your MySQL query statement below
SELECT
    Request_at AS Day,
    ROUND(SUM(IF(status!='completed',1,0))/COUNT(*),2) AS 'Cancellation Rate'
FROM
    (
        SELECT
            status,
            Request_at
        FROM
            Trips
        WHERE
            Request_at BETWEEN '2013-10-01' AND '2013-10-03'
            AND Client_Id NOT IN (SELECT Users_Id FROM Users WHERE Banned='Yes')
            AND Driver_Id NOT IN (SELECT Users_Id FROM Users WHERE Banned='Yes')
    ) AS A
GROUP BY
    Request_at;
