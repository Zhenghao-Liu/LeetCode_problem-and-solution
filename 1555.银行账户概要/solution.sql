# Write your MySQL query statement below
SELECT
    user_id,
    user_name,
    credit,
    CASE
        WHEN credit<0 THEN 'Yes'
        ELSE 'No'
    END AS credit_limit_breached
FROM
    (
        SELECT
            E.user_id,
            user_name,
            credit-TAB_OUP.output+TAB_INP.input AS credit
        FROM
            Users AS E
            INNER JOIN (
                SELECT
                    A.user_id,
                    SUM(IFNULL(B.amount,0)) AS output
                FROM
                    Users AS A
                    LEFT OUTER JOIN Transactions AS B
                ON
                    A.user_id=B.paid_by
                GROUP BY
                    A.user_id
            ) AS TAB_OUP ON E.user_id=TAB_OUP.user_id
            INNER JOIN (
                SELECT
                    C.user_id,
                    SUM(IFNULL(D.amount,0)) AS input
                FROM
                    Users AS C
                    LEFT OUTER JOIN Transactions AS D
                ON
                    C.user_id=D.paid_to
                GROUP BY
                    C.user_id
            ) AS TAB_INP ON E.user_id=TAB_INP.user_id
    ) AS F
