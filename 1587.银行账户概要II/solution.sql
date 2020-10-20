# Write your MySQL query statement below
SELECT
    B.name,
    SUM(A.amount) AS balance
FROM
    Transactions AS A
    RIGHT OUTER JOIN Users AS B
ON
    A.account=B.account
GROUP BY
    B.account
HAVING
    SUM(A.amount)>10000;
