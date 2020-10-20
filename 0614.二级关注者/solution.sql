# Write your MySQL query statement below
SELECT
    A.followee AS follower,
    COUNT(DISTINCT A.follower) AS num
FROM
    follow AS A
    RIGHT OUTER JOIN follow AS B
ON
    A.followee=B.follower
WHERE
    A.followee IS NOT NULL
GROUP BY
    A.followee
ORDER BY
    A.followee ASC;
