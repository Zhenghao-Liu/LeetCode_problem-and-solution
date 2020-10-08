# Write your MySQL query statement below
SELECT
    player_id,
    event_date,
    SUM(games_played) OVER (PARTITION BY player_id ORDER BY event_date ASC) AS games_played_so_far
FROM
    Activity
ORDER BY
    player_id ASC,
    event_date ASC;
