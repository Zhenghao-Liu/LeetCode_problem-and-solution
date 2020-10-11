# 别用item_id去判断，谁能想到不同的item_id还可能是同一个牌子
# Write your MySQL query statement below
SELECT
    C.user_id AS seller_id,
    IF(C.favorite_brand=D.item_brand,'yes','no') AS 2nd_item_fav_brand
FROM
    Users AS C
    LEFT OUTER JOIN (
        SELECT
            A.seller_id,A.item_id,B.item_brand
        FROM
            (
                SELECT seller_id,item_id,ROW_NUMBER() OVER (PARTITION BY seller_id ORDER BY order_date ASC) AS rank_c
                FROM Orders
            ) AS A
            INNER JOIN Items as B
        ON
            A.item_id=B.item_id
        WHERE A.rank_c=2
    ) AS D
ON
    C.user_id=D.seller_id
ORDER BY
    C.user_id ASC;
