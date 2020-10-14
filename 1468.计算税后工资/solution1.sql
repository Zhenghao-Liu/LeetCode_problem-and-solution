# Write your MySQL query statement below
SELECT
    A.company_id,
    A.employee_id,
    A.employee_name,
    CASE
        WHEN MAX_S<1000 THEN A.salary
        WHEN MAX_S>10000 THEN ROUND(A.salary*(1-0.49),0)
        ELSE ROUND(A.salary*(1-0.24),0)
    END AS salary
FROM
    Salaries AS A
    INNER JOIN (SELECT company_id,MAX(salary) AS MAX_S FROM Salaries GROUP BY company_id) AS B
ON
    A.company_id=B.company_id;
