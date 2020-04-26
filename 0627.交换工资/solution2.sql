# Write your MySQL query statement below
UPDATE
    salary
SET
    sex=CASE sex
            WHEN 'm' THEN 'f'
            WHEN 'f' Then 'm'
        END;
