# Write your MySQL query statement below
SELECT
    B.country_name,
    CASE
        WHEN AVG(weather_state)<=15 THEN 'Cold'
        WHEN AVG(weather_state)>=25 THEN 'Hot'
        ELSE 'Warm'
    END AS weather_type
FROM
    Weather AS A
    INNER JOIN Countries AS B
ON
    A.country_id=B.country_id
WHERE
    YEAR(A.day)=2019
    AND MONTH(A.day)=11
GROUP BY
    A.country_id;
