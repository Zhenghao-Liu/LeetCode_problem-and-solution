# Write your MySQL query statement below
SELECT
    DISTINCT viewer_id AS id
FROM
    Views
WHERE
    author_id=viewer_id
ORDER BY
    id ASC;
