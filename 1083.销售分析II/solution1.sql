# Write your MySQL query statement below
SELECT
    DISTINCT A.buyer_id
FROM
    Sales AS A
    INNER JOIN Product AS B
ON
    A.product_id=B.product_id
WHERE
    B.product_name='S8'
    AND A.buyer_id NOT IN (
        SELECT
            DISTINCT C.buyer_id
        FROM
            Sales AS C
            INNER JOIN Product AS D
        ON
            C.product_id=D.product_id
        WHERE
            D.product_name='iPhone'
    );
