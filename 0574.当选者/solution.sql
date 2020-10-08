# Write your MySQL query statement below
SELECT
    A.Name
FROM
    Candidate AS A
    INNER JOIN Vote AS B
ON
    A.id=B.CandidateId
GROUP BY
    A.Name
ORDER BY
    COUNT(*) DESC
LIMIT
    1;
