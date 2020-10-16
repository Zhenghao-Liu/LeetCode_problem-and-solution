#新增两列，将从后往前和从前往后的频数相加，两个数都需要大于等于总数一半，再取平均
#一个数集中最多有一半的数值小于中位数，也最多有一半的数值大于中位数。
# Write your MySQL query statement below
SELECT
    AVG(Number) AS median
FROM
    (
        SELECT
            Number,
            SUM(Frequency) OVER (ORDER BY Number ASC) AS front_prefix,
            SUM(Frequency) OVER (ORDER BY Number DESC) AS back_prefix
        FROM
            Numbers
        ORDER BY
            Number ASC
    ) AS A
WHERE
    front_prefix>=(SELECT SUM(Frequency) FROM Numbers)/2
    AND back_prefix>=(SELECT SUM(Frequency) FROM Numbers)/2;
