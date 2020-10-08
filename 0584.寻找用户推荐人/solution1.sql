/*
 * IFNULL(expr1,expr2)
 * 如果expr1不为NULL返回expr1，否则返回expr2
 */
# Write your MySQL query statement below
SELECT
    name
FROM
    customer
WHERE
    IFNULL(referee_id,0)!=2;
