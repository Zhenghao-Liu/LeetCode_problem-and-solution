# Write your MySQL query statement below
SELECT
    ad_id,
    CASE
        WHEN SUM(IF(action='Clicked',1,0))=0 AND SUM(IF(action='Viewed',1,0))=0 THEN 0.00
        ELSE ROUND(SUM(IF(action='Clicked',1,0))/SUM(IF(action!='Ignored',1,0))*100,2)
    END AS ctr
FROM
    Ads
GROUP BY
    ad_id
ORDER BY
    ctr DESC,
    ad_id ASC;
