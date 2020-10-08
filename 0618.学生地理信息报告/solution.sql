# Write your MySQL query statement below
SELECT
    MAX(IF(continent='America',name,null)) AS America,
    MAX(IF(continent='Asia',name,null)) AS Asia,
    MAX(IF(continent='Europe',name,null)) AS Europe
FROM
    (SELECT
        name,
        continent,
        ROW_NUMBER() OVER (PARTITION BY continent ORDER BY name ASC) AS rankc
    FROM
        student) AS A
GROUP BY
    rankc;
