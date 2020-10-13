# Write your MySQL query statement below
SELECT
    A.invoice_id,
    B.customer_name,
    A.price,
    COUNT(C.user_id) AS contacts_cnt,
    COUNT(D.email) AS trusted_contacts_cnt
FROM
    Invoices AS A
    INNER JOIN Customers AS B ON A.user_id = B.customer_id
    LEFT JOIN Contacts AS C ON B.customer_id = C.user_id
    LEFT JOIN Customers AS D ON C.contact_email = D.email
GROUP BY
    A.invoice_id
ORDER BY
    A.invoice_id;
