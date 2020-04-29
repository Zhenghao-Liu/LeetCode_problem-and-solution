# Write your MySQL query statement below
SELECT
    FirstName,LastName,City,State
FROM
    Address RIGHT OUTER JOIN Person
ON
    Address.PersonId=Person.PersonId;
