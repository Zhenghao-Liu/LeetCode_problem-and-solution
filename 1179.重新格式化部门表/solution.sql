# Write your MySQL query statement below
SELECT
    id,
    SUM(
            CASE month
                WHEN 'Jan' THEN revenue
                ELSE null
            END
        ) AS Jan_Revenue,
    SUM(
            CASE month
                WHEN 'Feb' THEN revenue
                ELSE null
            END
        ) AS Feb_Revenue,
    SUM(
            CASE month
                WHEN 'Mar' THEN revenue
                ELSE null
            END
        ) AS Mar_Revenue,
    SUM(
            CASE month
                WHEN 'Apr' THEN revenue
                ELSE null
            END
        ) AS Apr_Revenue,
    SUM(
            CASE month
                WHEN 'May' THEN revenue
                ELSE null
            END
        ) AS May_Revenue,
    SUM(
            CASE month
                WHEN 'Jun' THEN revenue
                ELSE null
            END
        ) AS Jun_Revenue,
    SUM(
            CASE month
                WHEN 'Jul' THEN revenue
                ELSE null
            END
        ) AS Jul_Revenue,
    SUM(
            CASE month
                WHEN 'Aug' THEN revenue
                ELSE null
            END
        ) AS Aug_Revenue,
    SUM(
            CASE month
                WHEN 'Sep' THEN revenue
                ELSE null
            END
        ) AS Sep_Revenue,
    SUM(
            CASE month
                WHEN 'Oct' THEN revenue
                ELSE null
            END
        ) AS Oct_Revenue,
    SUM(
            CASE month
                WHEN 'Nov' THEN revenue
                ELSE null
            END
        ) AS Nov_Revenue,
    SUM(
            CASE month
                WHEN 'Dec' THEN revenue
                ELSE null
            END
        ) AS Dec_Revenue
FROM
    Department
GROUP BY id;
