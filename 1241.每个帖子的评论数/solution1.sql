# Write your MySQL query statement below
SELECT
    A.post_id,
    IFNULL(B.number_of_comments,0) AS number_of_comments
FROM
    (
        SELECT
            DISTINCT sub_id AS post_id
        FROM
            Submissions
        WHERE
            parent_id IS NULL
        ORDER BY
            sub_id ASC )AS A
    LEFT OUTER JOIN (
        SELECT
            parent_id,
            COUNT(DISTINCT sub_id) AS number_of_comments
        FROM
            Submissions
        WHERE
            parent_id IS NOT NULL
        GROUP BY
            parent_id
    ) AS B
ON
    A.post_id=B.parent_id;
