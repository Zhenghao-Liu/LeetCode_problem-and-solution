# Write your MySQL query statement below
SELECT
    A.first_date AS login_date,
    COUNT(A.user_id) AS user_count
FROM
    (
        SELECT
            MIN(activity_date) AS first_date,
            user_id
        FROM
            Traffic
        WHERE
            activity='login'
        GROUP BY
            user_id
        HAVING DATEDIFF('2019-06-30',first_date)<=90
    ) AS A
GROUP BY
    A.first_date;
