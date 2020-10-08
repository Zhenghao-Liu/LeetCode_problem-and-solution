# Write your MySQL query statement below
SELECT
    DISTINCT A.id,
    CASE
        WHEN A.p_id IS NULL THEN 'Root'
        WHEN B.p_id IS NULL THEN 'Leaf'
        ELSE 'Inner'
    END AS Type
FROM
    Tree AS A
    LEFT OUTER JOIN Tree AS B
ON
    A.id=B.p_id
ORDER BY
    id ASC;
