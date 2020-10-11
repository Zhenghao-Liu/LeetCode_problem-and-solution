# Write your MySQL query statement below
SELECT
    DATE_FORMAT(trans_date,'%Y-%m') AS month,
    country,
    SUM(IF(state='approved',1,0)) AS approved_count,
    SUM(IF(state='approved',amount,0)) AS approved_amount,
    SUM(IF(state='chaback',1,0)) AS chargeback_count,
    SUM(IF(state='chaback',amount,0)) AS chargeback_amount
FROM
    (
        SELECT country,state,amount,trans_date
        FROM Transactions
        WHERE state!='declined'
        UNION ALL
        SELECT
            A.country,'chaback' AS state,A.amount,B.trans_date
        FROM Transactions AS A RIGHT OUTER JOIN Chargebacks AS B
        ON A.id=B.trans_id
    ) AS C
GROUP BY
    DATE_FORMAT(trans_date,'%Y-%m'),
    country;
