# Write your MySQL query statement below
SELECT
    ROUND(
        IFNULL(
            (SELECT COUNT(*) FROM 
                (SELECT player_id,MIN(event_date) AS first_date from Activity group by player_id) AS A 
                INNER JOIN Activity AS B 
                ON A.player_id=B.player_id AND DATEDIFF(B.event_date,A.first_date)=1)/
            (SELECT COUNT(DISTINCT player_id) FROM Activity)
        ,0)
    ,2) AS fraction;
