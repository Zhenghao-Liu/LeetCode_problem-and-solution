#部门前3高意味着同职业里比我工资高的人数最多只有2个
# Write your MySQL query statement below
SELECT
    D1.Name AS Department,
    E1.Name AS Employee,
    E1.Salary
FROM
    Employee AS E1 INNER JOIN Department AS D1
ON
    E1.DepartmentId=D1.Id
WHERE
    2>=(
        SELECT
            COUNT(DISTINCT Salary)
        FROM
            Employee AS E2
        WHERE
            E1.DepartmentId=E2.DepartmentId
            AND E2.Salary>E1.Salary
    );
