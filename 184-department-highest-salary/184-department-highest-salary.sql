# Write your MySQL query statement below
SELECT 
    d.name Department,
    e.name Employee,
    e.salary
FROM 
    Employee e JOIN Department d
    on e.departmentId = d.id
WHERE 
    e.salary = (SELECT MAX(ee.salary) FROM EMPLOYEE ee WHERE e.departmentId = ee.departmentId);