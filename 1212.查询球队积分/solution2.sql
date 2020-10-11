# Write your MySQL query statement below
SELECT
    A.team_id,
    A.team_name,
    SUM(
        CASE
            WHEN my_goal>oppo_goal THEN 3
            WHEN my_goal=oppo_goal THEN 1
            ELSE 0
        END
    ) AS num_points
FROM
    Teams AS A
    LEFT OUTER JOIN (
        SELECT
            host_team AS id,
            host_goals AS my_goal,
            guest_goals AS oppo_goal
        FROM
            Matches

        UNION ALL

        SELECT
            guest_team AS id,
            guest_goals AS my_goal,
            host_goals AS oppo_goal
        FROM
            Matches
    ) AS B
ON
    A.team_id=B.id
GROUP BY
    A.team_id
ORDER BY
    num_points DESC,
    A.team_id ASC;
    
