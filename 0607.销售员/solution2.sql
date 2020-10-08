# Write your MySQL query statement below
SELECT
    name
FROM
    salesperson
WHERE
    sales_id NOT IN (
        SELECT
            A.sales_id
        FROM
            orders AS A
            INNER JOIN company AS B
        ON
            A.com_id=B.com_id
        WHERE
            B.name='RED'
    );
