# Write your MySQL query statement below
SELECT
    IF (COUNT(*)=1,num,null) AS num
FROM
    (
        SELECT
            num
        FROM
            my_numbers
        GROUP BY
            num
        HAVING
            COUNT(*)=1
        ORDER BY
            num DESC
        LIMIT
            1
    ) AS A;
