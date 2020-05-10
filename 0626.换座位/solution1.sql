# Write your MySQL query statement below
SELECT
    (
        CASE
            WHEN id%2=1 AND id!=max_id THEN id+1
            WHEN id%2=1 AND id=max_id THEN id
            ELSE id-1
        END
    ) AS id,
    student
FROM
    seat,
    (
        SELECT
            COUNT(*) AS max_id
        FROM
            seat
    ) AS max_id_table
ORDER BY
    id ASC;
