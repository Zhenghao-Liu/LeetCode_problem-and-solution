# Write your MySQL query statement below
SELECT
    A.left_operand,
    A.operator,
    A.right_operand,
    CASE
        WHEN A.operator='=' AND B.value=C.value THEN 'true'
        WHEN A.operator='<' AND B.value<C.value THEN 'true'
        WHEN A.operator='>' AND B.value>C.value THEN 'true'
        ELSE 'false'
    END AS value
FROM
    Expressions AS A
    INNER JOIN Variables AS B ON A.left_operand=B.name
    INNER JOIN Variables AS C ON A.right_operand=C.name;
