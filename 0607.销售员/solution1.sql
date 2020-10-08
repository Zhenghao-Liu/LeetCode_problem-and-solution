# Write your MySQL query statement below
SELECT
    DISTINCT C.name
FROM
    orders AS A
    INNER JOIN company AS B ON A.com_id=B.com_id
    RIGHT OUTER JOIN salesperson AS C ON A.sales_id=C.sales_id
WHERE
    C.sales_id NOT IN (
        SELECT
            sales_id
        FROM
            orders AS D
            INNER JOIN company AS E
        ON
            D.com_id=E.com_id
        WHERE
            E.name='RED'
    );
