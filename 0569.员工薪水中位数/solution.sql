# Write your MySQL query statement below
SELECT
    Id,
    Company,
    Salary
FROM
    (
        SELECT
            Id,
            Company,
            Salary,
            ROW_NUMBER() OVER (PARTITION BY Company ORDER BY Salary ASC) AS rank_c,
            COUNT(*) OVER (PARTITION BY Company) AS count_c
        FROM
            Employee
    ) AS A
WHERE
    rank_c IN (count_c/2,count_c/2+1,(count_c+1)/2)
ORDER BY
    Company ASC;
