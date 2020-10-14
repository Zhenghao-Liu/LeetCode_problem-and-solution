# Write your MySQL query statement below
SELECT
    company_id,
    employee_id,
    employee_name,
    CASE
        WHEN MAX(salary) OVER (PARTITION BY company_id)<1000 THEN salary
        WHEN MAX(salary) OVER (PARTITION BY company_id)>10000 THEN ROUND(salary*(1-0.49),0)
        ELSE ROUND(salary*(1-0.24),0)
    END AS salary
FROM
    Salaries
ORDER BY
    company_id,
    employee_id;
