# Write your MySQL query statement below
SELECT
    C.pay_month,
    C.department_id,
    CASE
        WHEN C.department_avg>D.company_avg THEN 'higher'
        WHEN C.department_avg<D.company_avg THEN 'lower'
        ELSE 'same'
    END AS comparison
FROM
    (
        SELECT
            DATE_FORMAT(A.pay_date,'%Y-%m') AS pay_month,
            AVG(A.amount) AS department_avg,
            B.department_id
        FROM
            Salary AS A
            RIGHT OUTER JOIN employee AS B
        ON
            A.employee_id=B.employee_id
        GROUP BY
            DATE_FORMAT(A.pay_date,'%Y-%m'),
            B.department_id
    ) AS C
    INNER JOIN
    (
        SELECT
            DATE_FORMAT(pay_date,'%Y-%m') AS pay_month,
            AVG(amount) AS company_avg
        FROM
            Salary
        GROUP BY
            DATE_FORMAT(pay_date,'%Y-%m')
    ) AS D
ON
    C.pay_month=D.pay_month;
