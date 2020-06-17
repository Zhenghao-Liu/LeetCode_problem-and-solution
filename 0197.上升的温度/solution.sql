#和自己比较当然是要用到别名
# Write your MySQL query statement below
SELECT
    A.Id
FROM
    Weather AS A,
    Weather AS B
WHERE
    A.RecordDate=AddDate(B.RecordDate,INTERVAL 1 DAY)
    AND A.Temperature>B.Temperature;
