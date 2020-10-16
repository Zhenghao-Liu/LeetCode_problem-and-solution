# Write your MySQL query statement below
SELECT
    ROUND(
        IFNULL(
            (SELECT COUNT(DISTINCT session_id) FROM Activity WHERE DATEDIFF('2019-07-27',activity_date)<30)/
            (SELECT COUNT(DISTINCT user_id) FROM Activity WHERE DATEDIFF('2019-07-27',activity_date)<30) 
        ,0)
    ,2) AS average_sessions_per_user;
