# Write your MySQL query statement below
SELECT
    A.sub_id AS post_id,
    IFNULL(COUNT(DISTINCT B.sub_id),0) AS number_of_comments
FROM
    Submissions AS A
    LEFT OUTER JOIN Submissions AS B
ON
    A.sub_id=B.parent_id
WHERE
    A.parent_id IS NULL
GROUP BY
    A.sub_id
ORDER BY
    A.sub_id;
