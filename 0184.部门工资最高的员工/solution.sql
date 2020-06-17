#最后in不能单独以salary为列，因为查出来是一个数字的集合，可能在同一个departmentid里面排名不是第一的salary也在这个集合中
#所以要salary和departmentid同时为主键
# Write your MySQL query statement below
SELECT
    Department.Name AS Department,
    Employee.Name AS Employee,
    Employee.Salary
FROM
    Employee,
    Department
WHERE
    Employee.DepartmentId=Department.Id
    AND (Employee.Salary,Employee.DepartmentId) IN (SELECT
                                                    MAX(Salary),DepartmentId
                                                FROM
                                                    Employee
                                                GROUP BY DepartmentId);
