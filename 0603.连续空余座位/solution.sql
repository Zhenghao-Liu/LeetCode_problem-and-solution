# Write your MySQL query statement below
SELECT
    DISTINCT(A.seat_id)
FROM
    cinema AS A,
    cinema AS B
WHERE
    ABS(A.seat_id-B.seat_id)=1
    AND A.free=true
    AND B.free=true
ORDER BY
    A.seat_id ASC;
