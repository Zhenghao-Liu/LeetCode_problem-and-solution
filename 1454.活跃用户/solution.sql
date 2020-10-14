# Write your MySQL query statement below
SELECT
    A.id,
    B.name
FROM
    (
        SELECT
            DISTINCT id
        FROM
            (
                SELECT
                    id,
                    SUBDATE(login_date,rank_c) AS diff_c
                FROM
                    (
                        SELECT
                            id,
                            login_date,
                            ROW_NUMBER() OVER (PARTITION BY id ORDER BY login_date ASC) AS rank_c
                        FROM
                            (SELECT id,login_date FROM Logins GROUP BY id,login_date) AS DISTINCT_Logins
                    ) AS Diff_table
            ) AS Id_table
        GROUP BY
            id,diff_c
        HAVING
            COUNT(diff_c)>=5
    ) AS A
    INNER JOIN Accounts AS B
ON
    A.id=B.id
ORDER BY
    A.id;
