# Write your MySQL query statement below
SELECT
    p.email
FROM 
    Person p
GROUP BY email
HAVING COUNT(*) > 1;