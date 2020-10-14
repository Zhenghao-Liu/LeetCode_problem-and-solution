# Write your MySQL query statement below
SELECT
    user_id,
    name,
    mail
FROM
    Users
WHERE
    mail REGEXP '^[:alpha:][[:alpha:] | [:digit:] | _ | \\. | / | \\-]*@leetcode\\.com$';
