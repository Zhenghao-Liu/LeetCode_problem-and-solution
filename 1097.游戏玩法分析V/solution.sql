# Write your MySQL query statement below
SELECT
    A.install_dt,
    COUNT(A.player_id) AS installs,
    ROUND(COUNT(B.player_id)/COUNT(A.player_id),2) AS Day1_retention
FROM
    (
        SELECT
            player_id,MIN(event_date) AS install_dt
        FROM 
            activity 
        GROUP BY player_id
    ) AS A 
    LEFT OUTER JOIN Activity AS B 
ON
    A.player_id=B.player_id AND DATEDIFF(B.event_date,A.install_dt)=1
GROUP BY
    A.install_dt;
