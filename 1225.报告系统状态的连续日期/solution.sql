# Write your MySQL query statement below
SELECT
    period_state,
    MIN(date) AS start_date,
    MAX(date) AS end_date
FROM
    (
        SELECT
            date,rank_c,period_state
        FROM
        (
            SELECT fail_date AS date,DATEDIFF(fail_date,'2018-01-01')-(ROW_NUMBER() OVER (ORDER BY fail_date ASC)) AS rank_c,'failed' AS period_state 
            FROM Failed
            WHERE YEAR(fail_date)=2019
            UNION ALL
            SELECT success_date AS date,DATEDIFF(success_date,'2018-01-01')-(ROW_NUMBER() OVER (ORDER BY success_date ASC)) AS rank_c,'succeeded' AS period_state 
            FROM Succeeded
            WHERE YEAR(success_date)=2019Q
        ) AS A
        ORDER BY
            date
    ) AS B
GROUP BY
    B.rank_c,
    period_state
ORDER BY
    start_date ASC;
