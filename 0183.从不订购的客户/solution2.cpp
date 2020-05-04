# Write your MySQL query statement below
SELECT
    Name as 'Customers'
FROM
    Customers as a
    left join Orders as b
ON
    a.Id=b.CustomerId WHERE b.CustomerId IS NULL
