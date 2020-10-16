# Write your MySQL query statement below
SELECT
    IFNULL(ROUND(SUM(IF(T='acc',rate,0))/SUM(IF(T='req',rate,0)),2),0.00) AS accept_rate
FROM
    (
        SELECT
            COUNT(DISTINCT CONCAT_WS('-',sender_id,send_to_id)) AS rate,
            'req' AS T
        FROM
            friend_request
        UNION ALL
        SELECT
            COUNT(DISTINCT CONCAT_WS('-',requester_id,accepter_id)) AS rate,
            'acc' AS T
        FROM
            request_accepted
    ) AS A;
