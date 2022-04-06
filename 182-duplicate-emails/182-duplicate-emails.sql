# Write your MySQL query statement below
SELECT
    DISTINCT
    p.email
FROM 
    Person p
WHERE 1 < (SELECT COUNT(*) FROM Person pe WHERE p.email = pe.email);