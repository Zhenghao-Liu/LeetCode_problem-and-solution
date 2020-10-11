# Write your MySQL query statement below
SELECT
    A.book_id,
    A.name
FROM
    (
        SELECT
            book_id,name
        FROM
            Books
        WHERE
            DATEDIFF('2019-06-23',available_from)>30
    ) AS A
    LEFT OUTER JOIN
    (
        SELECT
            book_id,quantity
        FROM
            Orders
        WHERE
            DATEDIFF('2019-06-23',dispatch_date)<=365
    ) AS B
ON
    A.book_id=B.book_id
GROUP BY
    A.book_id
HAVING
    SUM(IFNULL(B.quantity,0))<10;
