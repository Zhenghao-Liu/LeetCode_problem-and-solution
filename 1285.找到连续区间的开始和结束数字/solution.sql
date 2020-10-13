/*
 * 连续区间的diff会相同
 * [ROW_NUMBER()](https://jingyan.baidu.com/article/9989c74604a644f648ecfef3.html)
 */
# Write your MySQL query statement below
SELECT
    MIN(A.log_id) AS start_id,
    MAX(A.log_id) AS end_id
FROM
    (
        SELECT
            log_id,
            (log_id) - (ROW_NUMBER() OVER (ORDER BY log_id ASC)) AS diff
        FROM
            Logs
    ) AS A
GROUP BY
    A.diff;
