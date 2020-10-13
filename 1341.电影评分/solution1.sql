# Write your MySQL query statement below
(SELECT
    B.name AS results
FROM
    Movie_Rating AS A
    INNER JOIN Users AS B
ON
    A.user_id=B.user_id
GROUP BY
    A.user_id
HAVING
    COUNT(*)>=ALL(SELECT COUNT(*) AS rank_c FROM Movie_Rating GROUP BY user_id)
ORDER BY
    name ASC
LIMIT
    1)

UNION ALL

(SELECT
    B.title AS results
FROM
    (
        SELECT
            movie_id,rating
        FROM
            Movie_Rating
        WHERE
            DATE_FORMAT(created_at,'%Y-%m')='2020-02'
    ) AS A
    INNER JOIN Movies AS B
ON
    A.movie_id=B.movie_id
GROUP BY
    A.movie_id
HAVING
    AVG(rating)>=ALL(SELECT AVG(rating) FROM Movie_Rating WHERE DATE_FORMAT(created_at,'%Y-%m')='2020-02' GROUP BY movie_id)
ORDER BY
    B.title ASC
LIMIT
    1);
    
