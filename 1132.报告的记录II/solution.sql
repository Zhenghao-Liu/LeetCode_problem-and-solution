# Write your MySQL query statement below
SELECT
    ROUND(AVG(rate)*100,2) AS average_daily_percent
FROM
    (
        SELECT
            COUNT(DISTINCT B.post_id)/COUNT(DISTINCT A.post_id) AS rate
        FROM
            (
                SELECT
                    post_id,
                    action_date
                FROM
                    Actions
                WHERE
                    action='report'
                    AND extra='spam'
            ) AS A
            LEFT OUTER JOIN Removals AS B
        ON
            A.post_id=B.post_id
        GROUP BY
            A.action_date
    ) AS C;
