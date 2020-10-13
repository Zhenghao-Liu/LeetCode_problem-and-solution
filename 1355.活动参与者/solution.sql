# 至少人数大于一个别的活动，至少人数小于一个别的活动，则是中间人数的活动
# Write your MySQL query statement below
SELECT
    activity
FROM
    Friends
GROUP BY
    activity
HAVING
    COUNT(name)>ANY(SELECT COUNT(name) FROM Friends GROUP BY activity)
    AND COUNT(name)<ANY(SELECT COUNT(name) FROM Friends GROUP BY activity);
