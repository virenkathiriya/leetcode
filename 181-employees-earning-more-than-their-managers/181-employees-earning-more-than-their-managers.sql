# Write your MySQL query statement below
SELECT 
    e.name Employee
FROM
    Employee e, Employee m
WHERE 
    e.managerId = m.id and e.salary > m.salary;