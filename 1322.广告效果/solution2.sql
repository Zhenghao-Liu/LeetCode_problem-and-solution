# mysql会把除法分母等于0的情况当做无效，即NULL，所以可以用IFNULL
# Write your MySQL query statement below
SELECT
    ad_id,
    ROUND(IFNULL(SUM(IF(action='Clicked',1,0))/SUM(IF(action!='Ignored',1,0))*100,0),2) AS ctr
FROM
    Ads
GROUP BY
    ad_id
ORDER BY
    ctr DESC,
    ad_id ASC;
