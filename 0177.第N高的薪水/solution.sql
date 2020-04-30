CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SELECT
        N-1
    INTO
        N;
    RETURN (
        # Write your MySQL query statement below.
        SELECT
        (
            SELECT DISTINCT
                Salary
            FROM
                Employee
            ORDER BY
                Salary DESC
            LIMIT
                N,1
        )
    );
END
