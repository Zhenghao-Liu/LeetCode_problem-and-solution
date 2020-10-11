# Write your MySQL query statement below
SELECT
    A.team_id,
    A.team_name,
    SUM(IFNULL(B.points,0)) AS num_points
FROM
    Teams AS A
    LEFT OUTER JOIN (
        SELECT
            host_team AS id,
            SUM(
                CASE
                    WHEN host_goals>guest_goals THEN 3
                    WHEN host_goals=guest_goals THEN 1
                    ELSE 0
                END
            ) AS points
        FROM
            Matches
        GROUP BY
            id

        UNION ALL

        SELECT
            guest_team AS id,
            SUM(
                CASE
                    WHEN host_goals<guest_goals THEN 3
                    WHEN host_goals=guest_goals THEN 1
                    ELSE 0
                END
            ) AS points
        FROM
            Matches
        GROUP BY
            id
    ) AS B
ON
    A.team_id=B.id
GROUP BY
    A.team_id
ORDER BY
    num_points DESC,
    A.team_id ASC;
    
