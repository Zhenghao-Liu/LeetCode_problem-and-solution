# Write your MySQL query statement below
SELECT
    x,
    y,
    z,
    CASE
        WHEN x<=z AND y<=z AND x+y>z THEN 'Yes'
        WHEN x<=y AND z<=y AND x+z>y THEN 'Yes'
        WHEN y<=x AND z<=x AND y+z>x THEN 'Yes'
        ELSE 'No'
    END AS triangle
FROM
    triangle;
