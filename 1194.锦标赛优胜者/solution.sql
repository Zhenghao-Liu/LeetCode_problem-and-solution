# Write your MySQL query statement below
SELECT
    D.group_id,
    D.player_id
FROM
    (
        SELECT
            C.group_id,
            C.player_id,
            ROW_NUMBER() OVER (PARTITION BY group_id ORDER BY B.s_score DESC,C.player_id ASC) AS rank_c
        FROM
            Players AS C
            LEFT OUTER JOIN (
                SELECT
                    A.player_id,
                    SUM(A.score) AS s_score
                FROM
                    ((SELECT first_player AS player_id,first_score AS score FROM matches) 
                    UNION ALL 
                    (SELECT second_player AS player_id,second_score AS score FROM matches)) AS A
                GROUP BY
                    A.player_id
            ) AS B
        ON
            C.player_id=B.player_id
    ) AS D
WHERE
    D.rank_c=1;
