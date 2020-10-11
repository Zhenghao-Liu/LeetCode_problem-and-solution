# Write your MySQL query statement below
SELECT
    A.spend_date,
    A.platform,
    IFNULL(SUM(B.person_amount),0) AS total_amount,
    COUNT(B.user_id) AS total_users
FROM
    (
        SELECT
            DISTINCT spend_date,'desktop' AS platform
        FROM
            Spending
        UNION ALL
        SELECT
            DISTINCT spend_date,'mobile' AS platform
        FROM
            Spending
        UNION ALL
        SELECT
            DISTINCT spend_date,'both' AS platform
        FROM
            Spending
    ) AS A
    LEFT OUTER JOIN (
        SELECT
            spend_date,
            user_id,
            IF(COUNT(DISTINCT platform)=1,platform,'both') AS platform,
            SUM(amount) AS person_amount
        FROM
            Spending
        GROUP BY
            spend_date,
            user_id
    ) AS B
ON
    A.spend_date=B.spend_date
    AND A.platform=B.platform
GROUP BY
    A.spend_date,
    A.platform;
