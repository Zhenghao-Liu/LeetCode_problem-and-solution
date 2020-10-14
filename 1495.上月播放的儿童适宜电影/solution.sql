# Write your MySQL query statement below
SELECT
    DISTINCT title
FROM
    (
        SELECT
            content_id
        FROM
            TVProgram
        WHERE
            DATE_FORMAT(program_date,'%Y-%m')='2020-06'
    ) AS A
    INNER JOIN
    (
        SELECT
            content_id,
            title
        FROM
            Content
        WHERE
            Kids_content='Y'
            AND content_type='Movies'
    ) AS B
ON
    A.content_id=B.content_id;
