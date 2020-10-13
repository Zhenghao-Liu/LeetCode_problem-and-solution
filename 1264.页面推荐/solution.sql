# Write your MySQL query statement below
SELECT
    DISTINCT page_id AS recommended_page
FROM
    Likes AS A
    INNER JOIN (SELECT user2_id AS id FROM Friendship WHERE user1_id=1
        UNION
        SELECT user1_id AS id FROM Friendship WHERE user2_id=1) AS B
ON
    A.user_id=B.id
WHERE
    A.page_id NOT IN (SELECT page_id FROM Likes WHERE user_id=1);
