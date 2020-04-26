# Write your MySQL query statement below
UPDATE
    salary
SET
    sex=char(ascii('m')+ascii('f')-ascii(sex));
