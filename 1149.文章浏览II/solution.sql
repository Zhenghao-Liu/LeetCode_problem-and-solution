# 看同一篇文章2次不算
# Write your MySQL query statement below
SELECT
    DISTINCT viewer_id AS id
FROM
    Views
GROUP BY
    viewer_id,view_date
HAVING
    COUNT(DISTINCT article_id)>=2
ORDER BY
    id ASC;
